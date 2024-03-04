#include <windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "input.h"

int init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.8, 0.5, 0.5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireCube(1.0f);

    // N�O � PRA USAR GLFLUSH
    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cena 3D");

    init();
    glutDisplayFunc(display);

    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(keyPressed_special);

    glutMainLoop();

    return 0;
}
