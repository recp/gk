/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef builtin_shader_h
#define builtin_shader_h

#include "../../include/gk/gk.h"
#include "../../include/gk/shader.h"

typedef enum GkBuiltinProg {
  GK_BUILTIN_PROG_RTT = 1
} GkBuiltinProg;

GkProgInfo*
gkBuiltinProg(GkBuiltinProg progtype);

#endif /* builtin_shader_h */