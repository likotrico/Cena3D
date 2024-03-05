#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

#include "render.h"

void renderTeapotHitbox(Teapot *teapot){
    //TROCAR ISSO POR OUTRA COISA
    glColor3f(1.0f, 0.0f, 0.0f);
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

        glVertex3f(teapot->hitbox_x, teapot->hitbox_y, teapot->hitbox_z);
        glVertex3f(teapot->hitbox_x, teapot->hitbox_y, -teapot->hitbox_z);
    glEnd();
}

void renderTeapot(Teapot *teapot){

    //TROCAR GLCOLOR
    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireTeapot(teapot->teapot_size);

    glTranslated(teapot->x, teapot->hitbox_y, teapot->hitbox_z);

    renderTeapotHitbox(teapot);

}
