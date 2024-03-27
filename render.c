#include "windows.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "render.h"
#include "input.h"

void renderTeapotHitbox(Teapot *teapot)
{
    // glColor3f(0.0f, 1.0f, 0.0f); // TROCAR ISSO POR OUTRA COISA

    glBegin(GL_LINES);

    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);
    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);

    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(-teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(-teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);

    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, teapot->hitbox_z);
    glVertex3f(teapot->hitbox_x, -teapot->hitbox_y, -teapot->hitbox_z);

    glEnd();
}

void renderTeapot(Teapot *teapot, float angle, float eixo_x, float eixo_y, float eixo_z)
{
    // teapot object, grau, eixo x, eixo y, eixo z

    glPushMatrix();

    // 0.20f, 0.70f, 1.0f, 1.0f
    float kd_teapot[4] = {0.20f, 0.70f, 1.0f, 1.0f};  // DEFINE A COR
    float ks_teapot[4] = {0.80f, 0.80f, 0.80f, 1.0f}; // DEFINE O QUAL CONCENTRADO FICA A LUZ NA SUPERFICIE
    float ambient[4] = {0.1f, 0.1f, 0.1f, 1.0f};
    float ns_teapot = 65.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd_teapot);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_teapot);
    glMaterialf(GL_FRONT, GL_SHININESS, ns_teapot);
    // glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);

    glTranslated(teapot->x, teapot->y, teapot->z);
    glRotatef(angle, eixo_x, eixo_y, eixo_z);

    if (WIRE_ON)
        glutWireTeapot(teapot->size);
    else
        glutSolidTeapot(teapot->size);

    if (HITBOX_ON)
        renderTeapotHitbox(teapot);

    glPopMatrix();
}

// ARRUMAR PARA ACOMPANHAR O VALOR DE X SEM PRECISAR DEPENDER DA MATRIX
void renderSphereHitbox(Sphere *sphere)
{
    // glColor3f(0.0f, 1.0f, 0.0f); // TROCAR ISSO POR OUTRA COISA

    glBegin(GL_LINES);

    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);
    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);

    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(-sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(-sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);

    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, sphere->hitbox_z);
    glVertex3f(sphere->hitbox_x, -sphere->hitbox_y, -sphere->hitbox_z);

    glEnd();
}

void renderSphere(Sphere *sphere)
{
    glPushMatrix();

    float kd_sphere[4] = {0.65f, 0.65f, 0.0f, 1.0f}; // DEFINE A COR
    float ks_sphere[4] = {0.9f, 0.9f, 0.9f, 1.0f};   // DEFINE O QUAL CONCENTRADO FICA A LUZ NA SUPERFICIE
    // float ambient_sphere[4] = {1.0f, 0.63f, 0.0f, 1.0f};
    float ambient_sphere[4] = {0.1f, 0.1f, 0.1f, 1.0f};
    float ns_sphere = 65.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd_sphere);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_sphere);
    // glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_sphere);
    glMaterialf(GL_FRONT, GL_SHININESS, ns_sphere);

    glTranslated(sphere->x, sphere->y, sphere->z);

    if (WIRE_ON)
        glutWireSphere(sphere->radius, sphere->slices, sphere->stacks);
    else
        glutSolidSphere(sphere->radius, sphere->slices, sphere->stacks);

    if (HITBOX_ON)
        renderSphereHitbox(sphere);

    glPopMatrix();
}

void renderTorusHitbox(Torus *torus)
{
    // glColor3f(0.0f, 1.0f, 0.0f); // TROCAR ISSO POR OUTRA COISA
    glBegin(GL_LINES);

    glVertex3f(-torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);
    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);
    glVertex3f(torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);
    glVertex3f(torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);
    glVertex3f(torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);
    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);

    glVertex3f(torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);
    glVertex3f(torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);
    glVertex3f(torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);
    glVertex3f(torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);
    glVertex3f(-torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(torus->hitbox_x, torus->hitbox_y, torus->hitbox_z);
    glVertex3f(torus->hitbox_x, torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);
    glVertex3f(-torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);

    glVertex3f(torus->hitbox_x, -torus->hitbox_y, torus->hitbox_z);
    glVertex3f(torus->hitbox_x, -torus->hitbox_y, -torus->hitbox_z);

    glEnd();
}

void renderTorus(Torus *torus, float angle, float eixo_x, float eixo_y, float eixo_z)
{
    // torus object, grau, eixo x, eixo y, eixo z

    glPushMatrix();

    // glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    float kd_torus[4] = {0.58f, 0.98f, 0.0f, 1.0f}; // DEFINE A COR
    float ks_torus[4] = {0.9f, 0.9f, 0.9f, 1.0f};   // DEFINE O QUAL CONCENTRADO FICA A LUZ NA SUPERFICIE
    float ns_torus = 50.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd_torus);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_torus);
    glMaterialf(GL_FRONT, GL_SHININESS, ns_torus);

    glTranslated(torus->x, torus->y, torus->z);
    glRotatef(angle, eixo_x, eixo_y, eixo_z);

    if (WIRE_ON)
        glutWireTorus(torus->innerRadius, torus->outerRadius, torus->sides, torus->rings);
    else
        glutSolidTorus(torus->innerRadius, torus->outerRadius, torus->sides, torus->rings);

    if (HITBOX_ON)
        renderTorusHitbox(torus);

    glPopMatrix();
}

void renderWireBlock(Block *block)
{
    // glColor3f(0.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA

    float kd_wire_block[4] = {0.0f, 0.0f, 0.0f, 1.0f}; // DEFINE A COR
    float ks_wire_block[4] = {0.9f, 0.9f, 0.9f, 1.0f}; // DEFINE O QUAL CONCENTRADO FICA A LUZ NA SUPERFICIE
    float ns_wire_block = 65.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd_wire_block);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_wire_block);
    glMaterialf(GL_FRONT, GL_SHININESS, ns_wire_block);

    glBegin(GL_LINES);

    glVertex3f(-block->hitbox_x, block->hitbox_y, -block->hitbox_z);
    glVertex3f(-block->hitbox_x, -block->hitbox_y, -block->hitbox_z);

    glVertex3f(block->hitbox_x, block->hitbox_y, -block->hitbox_z);
    glVertex3f(block->hitbox_x, -block->hitbox_y, -block->hitbox_z);

    glVertex3f(-block->hitbox_x, block->hitbox_y, -block->hitbox_z);
    glVertex3f(block->hitbox_x, block->hitbox_y, -block->hitbox_z);

    glVertex3f(-block->hitbox_x, -block->hitbox_y, -block->hitbox_z);
    glVertex3f(block->hitbox_x, -block->hitbox_y, -block->hitbox_z);

    glVertex3f(-block->hitbox_x, block->hitbox_y, block->hitbox_z);
    glVertex3f(-block->hitbox_x, -block->hitbox_y, block->hitbox_z);

    glVertex3f(block->hitbox_x, -block->hitbox_y, block->hitbox_z);
    glVertex3f(block->hitbox_x, block->hitbox_y, block->hitbox_z);

    glVertex3f(-block->hitbox_x, block->hitbox_y, block->hitbox_z);
    glVertex3f(block->hitbox_x, block->hitbox_y, block->hitbox_z);

    glVertex3f(-block->hitbox_x, -block->hitbox_y, block->hitbox_z);
    glVertex3f(block->hitbox_x, -block->hitbox_y, block->hitbox_z);

    glVertex3f(-block->hitbox_x, block->hitbox_y, block->hitbox_z);
    glVertex3f(-block->hitbox_x, block->hitbox_y, -block->hitbox_z);

    glVertex3f(block->hitbox_x, block->hitbox_y, block->hitbox_z);
    glVertex3f(block->hitbox_x, block->hitbox_y, -block->hitbox_z);

    glVertex3f(-block->hitbox_x, -block->hitbox_y, block->hitbox_z);
    glVertex3f(-block->hitbox_x, -block->hitbox_y, -block->hitbox_z);

    glVertex3f(block->hitbox_x, -block->hitbox_y, block->hitbox_z);
    glVertex3f(block->hitbox_x, -block->hitbox_y, -block->hitbox_z);

    glEnd();
}

void renderSolidBlock(Block *block)
{
    float kd_block[4] = {0.65f, 0.0f, 0.0f, 1.0f}; // DEFINE A COR
    float ks_block[4] = {0.9f, 0.9f, 0.9f, 1.0f};  // DEFINE O QUAL CONCENTRADO FICA A LUZ NA SUPERFICIE
    float ns_block = 65.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd_block);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_block);
    glMaterialf(GL_FRONT, GL_SHININESS, ns_block);

    // glColor3f(1.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA

    double x = block->hitbox_x;
    double y = block->hitbox_y;
    double z = block->hitbox_z;

    double v1[3] = {-x, -y, -z};
    double v2[3] = {-x, -y, z};
    double v3[3] = {x, -y, z};
    double v4[3] = {x, -y, -z};
    double v5[3] = {-x, y, -z};
    double v6[3] = {-x, y, z};
    double v7[3] = {x, y, z};
    double v8[3] = {x, y, -z};

    glBegin(GL_QUADS);
    // FACE 1
    // glNormal3dv(normalVector(v1, v2, v4));
    glNormal3d(0, -1, 0);
    glVertex3dv(v1); // v1
    glVertex3dv(v4); // v4
    glVertex3dv(v3); // v3
    glVertex3dv(v2); // v2

    // FACE 2
    // glNormal3dv(normalVector(v1, v2, v5));
    glNormal3d(0, 0, -1);
    glVertex3f(-x, -y, -z); // v1
    glVertex3f(-x, -y, z);  // v2
    glVertex3f(-x, y, z);   // v6
    glVertex3f(-x, y, -z);  // v5

    // FACE 3
    // glNormal3dv(normalVector(v3, v7, v4));
    glNormal3d(0, 0, 1);
    glVertex3f(x, -y, z);  // v3
    glVertex3f(x, -y, -z); // v4
    glVertex3f(x, y, -z);  // v8
    glVertex3f(x, y, z);   // v7

    // FACE 4
    // glNormal3dv(normalVector(v1, v2, v4));
    glNormal3d(-1, 0, 0);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, -y, -z);

    // FACE 5
    glNormal3d(1, 0, 0);
    glVertex3f(-x, -y, z); // v2
    glVertex3f(x, -y, z);  // v3
    glVertex3f(x, y, z);   // v7
    glVertex3f(-x, y, z);  // v6

    // FACE 6
    glNormal3d(0, 1, 0);
    glVertex3dv(v6);
    glVertex3dv(v7);
    glVertex3dv(v8);
    glVertex3dv(v5);
    /*glVertex3f(-x, y, z); //v6
    glVertex3f(x, y, z); //v7
    glVertex3f(x, y, -z); //v8
    glVertex3f(-x, y, -z); //v5*/

    glEnd();
}

void renderBlock(Block *block, float angle, float eixo_x, float eixo_y, float eixo_z)
{
    glPushMatrix();
    glTranslated(block->x, block->y, block->z);
    glRotatef(angle, eixo_x, eixo_y, eixo_z);

    if (WIRE_ON)
        renderWireBlock(block);
    else
        renderSolidBlock(block);

    glPopMatrix();
}

void drawScene()
{
    // Floor

    glPushMatrix();
    renderBlock(DATA.floor, 45, 0, 1, 0); // 45°
    glPopMatrix();

    // Walls

    glPushMatrix();

    renderBlock(DATA.wall1, 45, 0, 1, 0);

    glPopMatrix();

    renderBlock(DATA.wall2, 45, 0, 1, 0);

    glPopMatrix();

    glPopMatrix();

    // Objects

    renderTeapot(DATA.teapot, 235, 0, 1, 0);

    renderSphere(DATA.sphere);

    renderTorus(DATA.torus, 90, 1, 0, 0);
}
