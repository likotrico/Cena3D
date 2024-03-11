
#include "render.h"

void renderTeapotHitbox(Teapot *teapot){
    glColor3f(1.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderTeapot(Teapot *teapot){

    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glutWireTeapot(teapot->teapot_size);

    //glTranslated(teapot->x, teapot->y, teapot->z);

    renderTeapotHitbox(teapot);

}

void renderSphereHitbox(Sphere *sphere){
    glColor3f(1.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glutWireSphere(sphere->radius, sphere->slices, sphere->stacks);

    glTranslated(sphere->x, sphere->y, sphere->z);

    renderSphereHitbox(sphere);
}

void renderTorusHitbox(Torus *torus){
    glColor3f(1.0f, 0.0f, 0.0f); //TROCAR ISSO POR OUTRA COISA
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

void renderTorus(Torus *torus){

    glColor3f(0.0f, 0.0f, 1.0f); //TROCAR GLCOLOR
    glutWireTorus(torus->innerRadius, torus->outerRadius, torus->nsides, torus->rings);

    glTranslated(torus->x, torus->y, torus->z);

    renderTorusHitbox(torus);
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

    glTranslated(block->x, block->y, block->z);

    renderSolidBlock(block);

    //APENAS PARA VISUALIZAR AS BORDAS
    renderWireBlock(block);
}

void drawScene(){



}
