#include <windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "render.h"

void renderTeapotHitbox(Teapot *teapot){
    glColor3f(0.0f, 1.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderTeapot(Teapot *teapot, float angle, float eixo_x, float eixo_y, float eixo_z){ //teapot object, grau, eixo x, eixo y, eixo z

    glPushMatrix();

    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glTranslated(teapot->x, teapot->y, teapot->z);
    glRotatef(angle, eixo_x, eixo_y, eixo_z);
    glutWireTeapot(teapot->teapot_size);

    renderTeapotHitbox(teapot);

    glPopMatrix();
}
//ARRUMAR PARA ACOMPANHAR O VALOR DE X SEM PRECISAR DEPENDER DA MATRIX
void renderSphereHitbox(Sphere *sphere){
    glColor3f(0.0f, 1.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderSphere(Sphere *sphere){

    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glTranslated(sphere->x, sphere->y, sphere->z);
    glutWireSphere(sphere->radius, sphere->slices, sphere->stacks);

    //glLoadIdentity();
    renderSphereHitbox(sphere);
    glPopMatrix();
}

void renderTorusHitbox(Torus *torus){
    glColor3f(0.0f, 1.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderTorus(Torus *torus, float angle, float eixo_x, float eixo_y, float eixo_z){ //torus object, grau, eixo x, eixo y, eixo z

    glPushMatrix();

    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glTranslated(torus->x, torus->y, torus->z);
    glRotatef(angle, eixo_x, eixo_y, eixo_z);
    glutWireTorus(torus->innerRadius, torus->outerRadius, torus->nsides, torus->rings);

    renderTorusHitbox(torus);

    glPopMatrix();
}

void renderWireBlock(Block *block){
    glColor3f(0.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderSolidBlock(Block *block){
    glColor3f(1.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
    double x = block->hitbox_x;
    double y = block->hitbox_y;
    double z = block->hitbox_z;
    glBegin(GL_QUADS);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glVertex3f(x, -y, -z);

        glVertex3f(-x, -y, -z);
        glVertex3f(-x, y, -z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, -y, z);

        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, -z);

        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, -z);

        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, -y, z);

        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, y, z);

    glEnd();
}

void renderBlock(Block *block){

    glPushMatrix();
    glTranslated(block->x, block->y, block->z);

    renderSolidBlock(block);

    //APENAS PARA VISUALIZAR AS BORDAS
    renderWireBlock(block);

    glPopMatrix();
}

void drawScene(){


    //glPushMatrix();

    //glRotatef(90,0,1,0);
    //glRotatef(90,0,0,1);
    Block *chao = createBlock(0, -0.05, 0, 1, 0.05, 1);
    renderBlock(chao);

    Block *p1 = createBlock(1.05, 0.4, 0, 0.05, 0.5, 1);
    renderBlock(p1);

    Block *p2 = createBlock(0.05, 0.4, 1.05, 1.05, 0.5, 0.05);
    renderBlock(p2);

    //glPopMatrix();
    //glRotatef(235,0,1,0);
    Teapot *t = createTeapot(0.5, 0.14, -0.5, 0.2);
    renderTeapot(t, 235, 0, 1, 0);

    Sphere *s = createSphere(0.5, 0.2, 0.5, 0.2, 30, 30);
    renderSphere(s);

    Torus *tt = createTorus(-0.5, 0.1, 0, 0.1, 0.2, 30, 30);
    renderTorus(tt, 90, 1, 0, 0);

}
