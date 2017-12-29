/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#include "../common.h"

#include "shadows.h"
#include "../../include/gk/gk.h"
#include "../../include/gk/scene.h"
#include "../../include/gk/render.h"

#include "../../include/gk/prims/builtin-prim.h"
#include "../shader/builtin_shader.h"
#include "../program/uniform_cache.h"

#include "../shader/shader.h"
#include "../gpu_state/common.h"

#include "builtin/basic.h"
#include <ds/forward-list.h>

void *GK_SHADOWS_HANDLE                = &GK_SHADOWS_HANDLE;
GkShadowTechnType   gk__shadow_techn   = GK_SHADOW_DEFAULT;
gkSetupShadowsFunc  gk__setupShadowsFn = gkSetupBasicShadowMap;
gkRenderShadowsFunc gk__rnShadowsFn    = gkRenderBasicShadowMap;

GK_EXPORT
void
gkSetShadowTechn(GkShadowTechnType techn) {
  switch (techn) {
    case GK_SHADOW_BASIC_SHADOWMAP:
      gk__setupShadowsFn = gkSetupBasicShadowMap;
      break;
    default:
      break;
  }
}

GK_EXPORT
GkShadowTechnType
gkShadowTechn(void) {
  return gk__shadow_techn;
}

GkShadowMap*
gkSetupShadows(GkScene * __restrict scene) {
  return gk__setupShadowsFn(scene);
}

void
gkRenderShadows(GkScene * __restrict scene,
                GkLight * __restrict light) {
  gk__rnShadowsFn(scene, light);
}

GK_EXPORT
void
gkEnableShadows(GkScene * __restrict scene) {
  GkSceneImpl *sceneImpl;

  sceneImpl = (GkSceneImpl *)scene;
  sceneImpl->rpath = GK_RNPATH_SCENE_PERLIGHT;
  sceneImpl->rp    = gkScenePerLightRenderPath;
  scene->flags    |= GK_SCENEF_SHADOWS;

  flist_insert(gkContextOf(scene)->samplers, GK_SHADOWS_HANDLE);
}

GK_EXPORT
void
gkDisableShadows(GkScene * __restrict scene) {
  GkSceneImpl *sceneImpl;

  sceneImpl = (GkSceneImpl *)scene;
  sceneImpl->rpath = GK_RNPATH_MODEL_PERLIGHT;
  sceneImpl->rp    = gkModelPerLightRenderPath;
  scene->flags    &= ~GK_SCENEF_SHADOWS;

  flist_remove_by(gkContextOf(scene)->samplers, GK_SHADOWS_HANDLE);
}