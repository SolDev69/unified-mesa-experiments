/*
 * Copyright (C) 2017 Rob Clark <robclark@freedesktop.org>
 * Copyright © 2018 Google, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Rob Clark <robclark@freedesktop.org>
 */

#ifndef FD6_BLIT_H_
#define FD6_BLIT_H_

#include "pipe/p_state.h"

#include "freedreno_context.h"


template <chip CHIP>
void fd6_blitter_init(struct pipe_context *pctx);
unsigned fd6_tile_mode_for_format(enum pipe_format pfmt);
unsigned fd6_tile_mode(const struct pipe_resource *tmpl);

/*
 * Blitter APIs used by gmem for cases that need CP_BLIT's (r2d)
 * instead of CP_EVENT_WRITE::BLITs
 */

template <chip CHIP>
void fd6_clear_lrz(struct fd_batch *batch, struct fd_resource *zsbuf,
                   struct fd_bo *lrz, double depth) assert_dt;
template <chip CHIP>
void fd6_clear_surface(struct fd_context *ctx, struct fd_ringbuffer *ring,
                       struct pipe_surface *psurf, const struct pipe_box *box2d,
                       union pipe_color_union *color, uint32_t unknown_8c01) assert_dt;
template <chip CHIP>
void fd6_resolve_tile(struct fd_batch *batch, struct fd_ringbuffer *ring,
                      uint32_t base, struct pipe_surface *psurf, uint32_t unknown_8c01) assert_dt;

#endif /* FD6_BLIT_H_ */
