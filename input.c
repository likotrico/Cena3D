#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

void keyPressed(unsigned char key, int x, int y)
{
    // SELECIONA BULE
    if (key == '1')
    {
        printf("Bule selecinado!\n");
    }

    // SELECIONA BOLA
    if (key == '2')
    {
        printf("Bola selecinada!\n");
    }

    // SELECIONA TORO
    if (key == '3')
    {
        printf("Toro selecinado!\n");
    }
}

void keyPressed_special(int key, int x, int y)
{

    if (key == GLUT_KEY_LEFT)
    {
        printf("Movendo esquerda!\n");
    }

    if (key == GLUT_KEY_RIGHT)
    {
        printf("Movendo direita!\n");
    }

    if (key == GLUT_KEY_UP)
    {
        printf("Movendo cima!\n");
    }

    if (key == GLUT_KEY_DOWN)
    {
        printf("Movendo baixo!\n");
    }
}
