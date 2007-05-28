/******************************************************************
*
*	Wiimote for C++
*
*	Copyright (C) Satoshi Konno 2007
*
*	File:	X3DBrowserFunc.cpp
*
******************************************************************/

#ifndef _X3DBROWSERFUNC_H_
#define _X3DBROWSERFUNC_H_

#ifdef WIN32
#include <windows.h>
#endif

#ifdef CX3D_SUPPORT_OPENGL
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#ifdef CX3D_SUPPORT_GLUT
#include <GL/glut.h>
#endif

#include <cybergarage/x3d/CyberX3D.h>


using namespace CyberX3D;

enum {
MOUSE_BUTTON_NONE,
MOUSE_BUTTON_LEFT,
};

enum {
OGL_RENDERING_WIRE,
OGL_RENDERING_SHADE,
OGL_RENDERING_TEXTURE,
};

void MoveViewpoint(SceneGraph *sg, int width, int height, int mosx, int mosy);
void UpdateViewport(SceneGraph *sg, int width, int height);
void DrawSceneGraph(SceneGraph *sg, int drawMode);

#endif

