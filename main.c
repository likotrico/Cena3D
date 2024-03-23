#include "win.h"
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "input.h"
#include "render.h"

double FOV = 70;
double near_clip = -5;
double far_clip = 0;

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
    gluPerspective(FOV, 1, near_clip, far_clip);

    // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(-0.5, 0.3, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);

    lighting();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    glViewport(0, -150, 800, 800);
    drawScene();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(800, 600);
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
