#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include "input.h"
#include "object.h"

void keyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        printf("Log: Deselect.\n");
        SELECTED_TYPE = none_type;
        break;

    case '1':
        printf("Log: Teapot selected.\n");
        SELECTED_TYPE = teapot_type;
        break;

    case '2':
        printf("Log: Sphere selected.\n");
        SELECTED_TYPE = sphere_type;
        break;

    case '3':
        printf("Log: Torus selected.\n");
        SELECTED_TYPE = torus_type;
        break;

    default:
        break;
    }
}

void skeyPressed(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
    {
        printf("Log: Try move to left\n");
        moveObject(0, 0, -1);
    }

    if (key == GLUT_KEY_RIGHT)
    {
        printf("Log: Try move to right\n");
        moveObject(0, 0, 1);
    }

    if (key == GLUT_KEY_UP)
    {
        printf("Log: Try move to up\n");
        moveObject(1, 0, 0);
    }

    if (key == GLUT_KEY_DOWN)
    {
        printf("Log: Try move to down\n");
        moveObject(-1, 0, 0);
    }
}

void moveObject(double x, double y, double z)
{
    if (!(-1 <= x <= 1 && -1 <= y <= 1 && -1 <= z <= 1))
    {
        printf("Error: Movement vector passed not unitary.\n");
        exit(1);
    }

    x *= SPEED;
    y *= SPEED;
    z *= SPEED;

    switch (SELECTED_TYPE)
    {
    case none_type:
        printf("Log: No object selected.\n");
        break;

    case teapot_type:
        printf("Log: Moving teapot.\n");
        moveTeapot(DATA.teapot, x, y, z);
        break;

    case sphere_type:
        printf("Log: Moving sphere.\n");
        moveSphere(DATA.sphere, x, y, z);
        break;

    case torus_type:
        printf("Log: Moving torus.\n");
        moveTorus(DATA.torus, x, y, z);
        break;

    default:
        printf("Error: Invalid object type.\n");
        exit(1);
        break;
    }

    glutPostRedisplay();
}
