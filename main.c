#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

#include "input.h"
#include "render.h"

int init(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.5, 0.5, 0.5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    //Teapot *t = createTeapot(0, 0, 0, 1);
    //renderTeapot(t);
    //Sphere *s = createSphere(0, 0, 0, 0.5, 50, 50);
    //renderSphere(s);
    /*double inner = 0.2;
    double outer = 0.7;
    Torus *t1 = createTorus(0, 0, 0, inner, outer, 30, 50);
    renderTorus(t1);*/
    //Block *b = createBlock(0, 0, 0, 0.5, 1, 0.5);
    //renderBlock(b);

    //PONTOS PARA TESTAR HITBOX
    /*glColor3f(0, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex3f(0, 0, 0);
    glEnd();*/

    //NÃO É PRA USAR GLFLUSH
    glFlush();
    //glutSwapBuffers();

}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
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
