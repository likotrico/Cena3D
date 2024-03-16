#include <windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#include "input.h"
#include "render.h"


int init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-0.5, 0.3, -0.00,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    //Teapot *t = createTeapot(-0.5, 0, -0.2, 0.2);
    //glRotatef(235,0,1,0);
    //renderTeapot(t);
    drawScene();
    //Sphere *s = createSphere(0, 0, 0, 0.5, 50, 50);
    //renderSphere(s);
    //Sphere *s1 = createSphere(1, 0, 1, 0.25, 50, 50);
    //renderSphere(s1);
    //double inner = 0.2;
    //double outer = 0.7;
    //Torus *t1 = createTorus(-1, -0.5, 0, inner, outer, 30, 50);
    //renderTorus(t1);
    //Block *b = createBlock(0, 0, 0, 0.5, 1, 0.5);
    //renderBlock(b);

    //PONTOS PARA TESTAR HITBOX
    glColor3f(0, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
        //glVertex3f(0.5, 0.3, -0.5);
        //glVertex3f(0, -0.05, 0);

        glVertex3f(0.74246, 0, -0.74246);
        glVertex3f(1, 0, 0);
        //glVertex3f(0, 1, 0);
        glVertex3f(0, 0, 1);
    glEnd();


    glutSwapBuffers();

}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Cena 3D");

    init();
    initData();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(skeyPressed);

    glutMainLoop();

    freeData();

    return 0;
}
