#ifndef RENDER_H
#define RENDER_H

#include "object.h"

void renderTeapot(Teapot *, float, float, float, float);
void renderSphere(Sphere *);
void renderTorus(Torus *, float, float, float, float);
void renderBlock(Block *, float , float , float , float );

void drawScene();


#endif
