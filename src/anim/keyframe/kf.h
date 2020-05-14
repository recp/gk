/*
 * This file is part of the gk project (https://github.com/recp/gk)
 * Copyright (c) Recep Aslantas.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "../../common.h"
#include "../../../include/gk/animation.h"

_gk_hide
bool
gkBuiltinKeyAnim(GkAnimation *anim,
                 GkChannel   *channel,
                 GkValue     *to,
                 GkValue     *delta);

void
gkRunKFAnim(GkKeyFrameAnimation *kfa, float ease);

GK_EXPORT
void
gkChannelSetTargetTo(GkChannel        * __restrict ch,
                     GkFloatOrPointer * __restrict to);

GK_EXPORT
void
gkPrepChannel(GkAnimation *anim, GkChannel *ch);

GK_EXPORT
void
gkPrepChannelKey(GkKeyFrameAnimation *anim, GkChannel *ch);
