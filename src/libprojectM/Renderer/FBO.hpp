 /**
 * projectM -- Milkdrop-esque visualisation SDK
 * Copyright (C)2003-2007 projectM Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * See 'LICENSE.txt' included within this release
 *
 */
/**
 * $Id: FBO.hpp,v 1.1.1.1 2005/12/23 18:05:00 psperl Exp $
 *
 * Opaque render target
 *
 */

#ifndef _RENDERTARGET_H
#define _RENDERTARGET_H

#include "projectM-opengl.h"

typedef enum { SCALE_NEAREST, SCALE_MAGNIFY, SCALE_MINIFY } TextureScale;

class RenderTarget {


public:
    /** Texture size */
    int texsize;

  int useFBO;
  int renderToTexture;

  ~RenderTarget();

  RenderTarget( int texsize, int width, int height );
  void lock();
  void unlock();
  GLuint initRenderToTexture();
  int nearestPower2( int value, TextureScale scaleRule );

    /** Opaque pbuffer context and pbuffer */
/*
#ifdef __APPLE__
    void *origContext;
    void *pbufferContext;
    void *pbuffer;
#endif
*/
    /** Render target texture ID for non-pbuffer systems */
    GLuint textureID[3];
#ifdef USE_FBO
    GLuint fbuffer[2];
    GLuint depthb[2];
#endif
  };



#endif /** !_RENDERTARGET_H */
