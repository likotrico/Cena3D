#include "windows.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "input.h"
#include "object.h"
#include "physics.h"
#include "render.h"

void lighting()
{
    float position[4] = {0.0f, 2.0f, 0.0f, 0.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float diffuse[4] = {0.8f, 0.8f, 0.8f, 1.0f};
    float black[4] = {0.25f, 0.25f, 0.25f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    float global_ambient[4] = {0.2f, 0.2f, 0.2f, 0.1f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

int init()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 1, 0.01, 10);

    lighting();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double eyeX = (1 + ZOOM * INC_Z) * -2;
    double eyeY = (1 + ZOOM * INC_Z) * 2;
    double eyeZ = (1 + ZOOM * INC_Z) * 0;
    double aimX = 0;
    double aimY = 0;
    double aimZ = 0;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, aimX, aimY, aimZ, 0, 1, 0);

    fall();
    drawScene();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 0);
    glutInitWindowSize(640, 640);
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
