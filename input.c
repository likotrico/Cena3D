#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <math.h>

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

double *calc_eq_reta(double z1, double x1, double z2, double x2){
    double *result;
    result = (double*)malloc(sizeof(double)*2); //coeficiente a e b de uma equação do primeiro grau
    result[0] = (x1-x2)/(z1-z2);
    result[1] = ((z1*x2) - (z2*x1))/(z1-z2);

    printf("a: %.3f", result[0]);
    printf("b: %.3f", result[1]);

    return result;

}

int isAbovep1(double z0, double x0){ //verifica se está acima da parede esquerda

    double y;
    double a = 1;
    double b = 1.414;

    y = a*z0 + b;
    //printf("y:%f\n",y);
    //printf("x:%f\n", x0);
    //printf("z:%f\n", z0);
    if(x0 >= y) return 1;

    return 0;
}

int isAbovep2(double z0, double x0){ //verifica se está acima da parede direita

    double y;
    double a = -1;
    double b = 1.414;

    y = a*z0 + b;
    //printf("y:%f\n",y);
    //printf("x:%f\n", x0);
    //printf("z:%f\n", z0);
    if(x0 >= y) return 1;

    return 0;
}

int verifyColision(int esq, int dir, int baixo, int cima){

    //y = x + 1.414 parede direita

    //y = -x + 1.414 parede esquerda


    switch (SELECTED_TYPE)
    {
    case none_type:
        printf("Log: No object selected.\n");
        break;

    case teapot_type:
        printf("Log: Verifying teapot move.\n");

        double v1[2] = {DATA.teapot->z+DATA.teapot->hitbox_z+0.13,
                        DATA.teapot->x + DATA.teapot->hitbox_x - 0.13};

        double v2[2] = {DATA.teapot->z-DATA.teapot->hitbox_z-0.13,
                        DATA.teapot->x - DATA.teapot->hitbox_x + 0.13};

        double v3[2] = {DATA.teapot->z-DATA.teapot->hitbox_z-0.13,
                        DATA.teapot->x + DATA.teapot->hitbox_x - 0.13};
        double v4[2] = {DATA.teapot->z+DATA.teapot->hitbox_z+0.13,
                        DATA.teapot->x - DATA.teapot->hitbox_x + 0.13};

        if(cima == 1){
            /*printf("r:\n");
            printf("v1: %d\n", isAbovep1(v1[0] + 0.0, v1[1] + 0.1));
            printf("v2: %d\n", isAbovep1(v2[0] + 0.0, v2[1] + 0.1));
            printf("v3: %d\n", isAbovep1(v3[0] + 0.0, v3[1] + 0.1));
            printf("v4: %d\n", isAbovep1(v4[0] + 0.0, v4[1] + 0.1));

            printf("s:\n");
            printf("v1: %d\n", isAbovep2(v1[0] + 0.0, v1[1] + 0.1));
            printf("v2: %d\n", isAbovep2(v2[0] + 0.0, v2[1] + 0.1));
            printf("v3: %d\n", isAbovep2(v3[0] + 0.0, v3[1] + 0.1));
            printf("v4: %d\n", isAbovep2(v4[0] + 0.0, v4[1] + 0.1));*/

            if(isAbovep1(v1[0] + 0.0, v1[1] + 0.1) || isAbovep1(v2[0] + 0.0, v2[1] + 0.1) || isAbovep1(v3[0] + 0.0, v3[1] + 0.1) || isAbovep1(v4[0] + 0.0, v4[1] + 0.1)) return 1;
            if(isAbovep2(v1[0] + 0.0, v1[1] + 0.1) || isAbovep2(v2[0] + 0.0, v2[1] + 0.1) || isAbovep2(v3[0] + 0.0, v3[1] + 0.1) || isAbovep2(v4[0] + 0.0, v4[1] + 0.1)) return 1;
        }
        else if(baixo == 1){
            /*printf("r:\n");
            printf("v1: %d\n", isAbovep1(v1[0] + 0.0, v1[1] - 0.1));
            printf("v2: %d\n", isAbovep1(v2[0] + 0.0, v2[1] - 0.1));
            printf("v3: %d\n", isAbovep1(v3[0] + 0.0, v3[1] - 0.1));
            printf("v4: %d\n", isAbovep1(v4[0] + 0.0, v4[1] - 0.1));

            printf("s:\n");
            printf("v1: %d\n", isAbovep2(v1[0] + 0.0, v1[1] - 0.1));
            printf("v2: %d\n", isAbovep2(v2[0] + 0.0, v2[1] - 0.1));
            printf("v3: %d\n", isAbovep2(v3[0] + 0.0, v3[1] - 0.1));
            printf("v4: %d\n", isAbovep2(v4[0] + 0.0, v4[1] - 0.1));*/

            if(isAbovep1(v1[0] + 0.0, v1[1] - 0.1) || isAbovep1(v2[0] + 0.0, v2[1] - 0.1) || isAbovep1(v3[0] + 0.0, v3[1] - 0.1) || isAbovep1(v4[0] + 0.0, v4[1] - 0.1)) return 1;
            if(isAbovep2(v1[0] + 0.0, v1[1] - 0.1) || isAbovep2(v2[0] + 0.0, v2[1] - 0.1) || isAbovep2(v3[0] + 0.0, v3[1] - 0.1) || isAbovep2(v4[0] + 0.0, v4[1] - 0.1)) return 1;
        }
        else if(esq == 1){
            /*printf("r:\n");
            printf("v1: %d\n", isAbovep1(v1[0] - 0.1, v1[1] + 0.0));
            printf("v2: %d\n", isAbovep1(v2[0] - 0.1, v2[1] + 0.0));
            printf("v3: %d\n", isAbovep1(v3[0] - 0.1, v3[1] + 0.0));
            printf("v4: %d\n", isAbovep1(v4[0] - 0.1, v4[1] + 0.0));

            printf("s:\n");
            printf("v1: %d\n", isAbovep2(v1[0] - 0.1, v1[1] + 0.0));
            printf("v2: %d\n", isAbovep2(v2[0] - 0.1, v2[1] + 0.0));
            printf("v3: %d\n", isAbovep2(v3[0] - 0.1, v3[1] + 0.0));
            printf("v4: %d\n", isAbovep2(v4[0] - 0.1, v4[1] + 0.0));*/

            if(isAbovep1(v1[0] - 0.1, v1[1] + 0.0) || isAbovep1(v2[0] - 0.1, v2[1] + 0.0) || isAbovep1(v3[0] - 0.1, v3[1] + 0.0) || isAbovep1(v4[0] - 0.1, v4[1] + 0.0)) return 1;
            if(isAbovep2(v1[0] - 0.1, v1[1] + 0.0) || isAbovep2(v2[0] - 0.1, v2[1] + 0.0) || isAbovep2(v3[0] - 0.1, v3[1] + 0.0) || isAbovep2(v4[0] - 0.1, v4[1] + 0.0)) return 1;
        }
        else if(dir == 1){
            /*printf("r:\n");
            printf("v1: %d\n", isAbovep1(v1[0] + 0.1, v1[1] + 0.0));
            printf("v2: %d\n", isAbovep1(v2[0] + 0.1, v2[1] + 0.0));
            printf("v3: %d\n", isAbovep1(v3[0] + 0.1, v3[1] + 0.0));
            printf("v4: %d\n", isAbovep1(v4[0] + 0.1, v4[1] + 0.0));

            printf("s:\n");
            printf("v1: %d\n", isAbovep2(v1[0] + 0.1, v1[1] + 0.0));
            printf("v2: %d\n", isAbovep2(v2[0] + 0.1, v2[1] + 0.0));
            printf("v3: %d\n", isAbovep2(v3[0] + 0.1, v3[1] + 0.0));
            printf("v4: %d\n", isAbovep2(v4[0] + 0.1, v4[1] + 0.0));*/

            if(isAbovep1(v1[0] + 0.1, v1[1] + 0.0) || isAbovep1(v2[0] + 0.1, v2[1] + 0.0) || isAbovep1(v3[0] + 0.1, v3[1] + 0.0) || isAbovep1(v4[0] + 0.1, v4[1] + 0.0)) return 1;
            if(isAbovep2(v1[0] + 0.1, v1[1] + 0.0) || isAbovep2(v2[0] + 0.1, v2[1] + 0.0) || isAbovep2(v3[0] + 0.1, v3[1] + 0.0) || isAbovep2(v4[0] + 0.1, v4[1] + 0.0)) return 1;
        }

        break;

    case sphere_type:
        printf("Log: Verifying sphere move.\n");

        double v1s[2] = {DATA.sphere->z+DATA.sphere->hitbox_z,
                        DATA.sphere->x + DATA.sphere->hitbox_x};

        double v2s[2] = {DATA.sphere->z-DATA.sphere->hitbox_z,
                        DATA.sphere->x - DATA.sphere->hitbox_x};

        double v3s[2] = {DATA.sphere->z-DATA.sphere->hitbox_z,
                        DATA.sphere->x + DATA.sphere->hitbox_x};

        double v4s[2] = {DATA.sphere->z+DATA.sphere->hitbox_z,
                        DATA.sphere->x - DATA.sphere->hitbox_x};

        if(cima == 1){
            /*printf("r:\n");
            printf("v1s: %d\n", isAbovep1(v1s[0] + 0.0, v1s[1] + 0.1));
            printf("v2s: %d\n", isAbovep1(v2s[0] + 0.0, v2s[1] + 0.1));
            printf("v3s: %d\n", isAbovep1(v3s[0] + 0.0, v3s[1] + 0.1));
            printf("v4s: %d\n", isAbovep1(v4s[0] + 0.0, v4s[1] + 0.1));

            printf("s:\n");
            printf("v1s: %d\n", isAbovep2(v1s[0] + 0.0, v1s[1] + 0.1));
            printf("v2s: %d\n", isAbovep2(v2s[0] + 0.0, v2s[1] + 0.1));
            printf("v3s: %d\n", isAbovep2(v3s[0] + 0.0, v3s[1] + 0.1));
            printf("v4s: %d\n", isAbovep2(v4s[0] + 0.0, v4s[1] + 0.1));*/

            if(isAbovep1(v1s[0] + 0.0, v1s[1] + 0.1) || isAbovep1(v2s[0] + 0.0, v2s[1] + 0.1) || isAbovep1(v3s[0] + 0.0, v3s[1] + 0.1) || isAbovep1(v4s[0] + 0.0, v4s[1] + 0.1)) return 1;
            if(isAbovep2(v1s[0] + 0.0, v1s[1] + 0.1) || isAbovep2(v2s[0] + 0.0, v2s[1] + 0.1) || isAbovep2(v3s[0] + 0.0, v3s[1] + 0.1) || isAbovep2(v4s[0] + 0.0, v4s[1] + 0.1)) return 1;
        }
        else if(baixo == 1){
            /*printf("r:\n");
            printf("v1s: %d\n", isAbovep1(v1s[0] + 0.0, v1s[1] - 0.1));
            printf("v2s: %d\n", isAbovep1(v2s[0] + 0.0, v2s[1] - 0.1));
            printf("v3s: %d\n", isAbovep1(v3s[0] + 0.0, v3s[1] - 0.1));
            printf("v4s: %d\n", isAbovep1(v4s[0] + 0.0, v4s[1] - 0.1));

            printf("s:\n");
            printf("v1s: %d\n", isAbovep2(v1s[0] + 0.0, v1s[1] - 0.1));
            printf("v2s: %d\n", isAbovep2(v2s[0] + 0.0, v2s[1] - 0.1));
            printf("v3s: %d\n", isAbovep2(v3s[0] + 0.0, v3s[1] - 0.1));
            printf("v4s: %d\n", isAbovep2(v4s[0] + 0.0, v4s[1] - 0.1));*/

            if(isAbovep1(v1s[0] + 0.0, v1s[1] - 0.1) || isAbovep1(v2s[0] + 0.0, v2s[1] - 0.1) || isAbovep1(v3s[0] + 0.0, v3s[1] - 0.1) || isAbovep1(v4s[0] + 0.0, v4s[1] - 0.1)) return 1;
            if(isAbovep2(v1s[0] + 0.0, v1s[1] - 0.1) || isAbovep2(v2s[0] + 0.0, v2s[1] - 0.1) || isAbovep2(v3s[0] + 0.0, v3s[1] - 0.1) || isAbovep2(v4s[0] + 0.0, v4s[1] - 0.1)) return 1;
        }
        else if(esq == 1){
            /*printf("r:\n");
            printf("v1s: %d\n", isAbovep1(v1s[0] - 0.1, v1s[1] + 0.0));
            printf("v2s: %d\n", isAbovep1(v2s[0] - 0.1, v2s[1] + 0.0));
            printf("v3s: %d\n", isAbovep1(v3s[0] - 0.1, v3s[1] + 0.0));
            printf("v4s: %d\n", isAbovep1(v4s[0] - 0.1, v4s[1] + 0.0));

            printf("s:\n");
            printf("v1s: %d\n", isAbovep2(v1s[0] - 0.1, v1s[1] + 0.0));
            printf("v2s: %d\n", isAbovep2(v2s[0] - 0.1, v2s[1] + 0.0));
            printf("v3s: %d\n", isAbovep2(v3s[0] - 0.1, v3s[1] + 0.0));
            printf("v4s: %d\n", isAbovep2(v4s[0] - 0.1, v4s[1] + 0.0));*/

            if(isAbovep1(v1s[0] - 0.1, v1s[1] + 0.0) || isAbovep1(v2s[0] - 0.1, v2s[1] + 0.0) || isAbovep1(v3s[0] - 0.1, v3s[1] + 0.0) || isAbovep1(v4s[0] - 0.1, v4s[1] + 0.0)) return 1;
            if(isAbovep2(v1s[0] - 0.1, v1s[1] + 0.0) || isAbovep2(v2s[0] - 0.1, v2s[1] + 0.0) || isAbovep2(v3s[0] - 0.1, v3s[1] + 0.0) || isAbovep2(v4s[0] - 0.1, v4s[1] + 0.0)) return 1;
        }
        else if(dir == 1){
            /*printf("r:\n");
            printf("v1s: %d\n", isAbovep1(v1s[0] + 0.1, v1s[1] + 0.0));
            printf("v2s: %d\n", isAbovep1(v2s[0] + 0.1, v2s[1] + 0.0));
            printf("v3s: %d\n", isAbovep1(v3s[0] + 0.1, v3s[1] + 0.0));
            printf("v4s: %d\n", isAbovep1(v4s[0] + 0.1, v4s[1] + 0.0));

            printf("s:\n");
            printf("v1s: %d\n", isAbovep2(v1s[0] + 0.1, v1s[1] + 0.0));
            printf("v2s: %d\n", isAbovep2(v2s[0] + 0.1, v2s[1] + 0.0));
            printf("v3s: %d\n", isAbovep2(v3s[0] + 0.1, v3s[1] + 0.0));
            printf("v4s: %d\n", isAbovep2(v4s[0] + 0.1, v4s[1] + 0.0));*/

            if(isAbovep1(v1s[0] + 0.1, v1s[1] + 0.0) || isAbovep1(v2s[0] + 0.1, v2s[1] + 0.0) || isAbovep1(v3s[0] + 0.1, v3s[1] + 0.0) || isAbovep1(v4s[0] + 0.1, v4s[1] + 0.0)) return 1;
            if(isAbovep2(v1s[0] + 0.1, v1s[1] + 0.0) || isAbovep2(v2s[0] + 0.1, v2s[1] + 0.0) || isAbovep2(v3s[0] + 0.1, v3s[1] + 0.0) || isAbovep2(v4s[0] + 0.1, v4s[1] + 0.0)) return 1;
        }

        break;

    case torus_type:
        printf("Log: Verifying torus move.\n");

        double v1t[2] = {DATA.torus->z+DATA.torus->hitbox_z + 0.2,
                         DATA.torus->x + DATA.torus->hitbox_x};

        double v2t[2] = {DATA.torus->z-DATA.torus->hitbox_z - 0.2,
                         DATA.torus->x - DATA.torus->hitbox_x};

        double v3t[2] = {DATA.torus->z-DATA.torus->hitbox_z - 0.2,
                         DATA.torus->x + DATA.torus->hitbox_x};

        double v4t[2] = {DATA.torus->z+DATA.torus->hitbox_z + 0.2,
                         DATA.torus->x - DATA.torus->hitbox_x};

        if(cima == 1){
            /*printf("r:\n");
            printf("v1t: %d\n", isAbovep1(v1t[0] + 0.0, v1t[1] + 0.1));
            printf("v2t: %d\n", isAbovep1(v2t[0] + 0.0, v2t[1] + 0.1));
            printf("v3t: %d\n", isAbovep1(v3t[0] + 0.0, v3t[1] + 0.1));
            printf("v4t: %d\n", isAbovep1(v4t[0] + 0.0, v4t[1] + 0.1));

            printf("s:\n");
            printf("v1t: %d\n", isAbovep2(v1t[0] + 0.0, v1t[1] + 0.1));
            printf("v2t: %d\n", isAbovep2(v2t[0] + 0.0, v2t[1] + 0.1));
            printf("v3t: %d\n", isAbovep2(v3t[0] + 0.0, v3t[1] + 0.1));
            printf("v4t: %d\n", isAbovep2(v4t[0] + 0.0, v4t[1] + 0.1));*/

            if(isAbovep1(v1t[0] + 0.0, v1t[1] + 0.1) || isAbovep1(v2t[0] + 0.0, v2t[1] + 0.1) || isAbovep1(v3t[0] + 0.0, v3t[1] + 0.1) || isAbovep1(v4t[0] + 0.0, v4t[1] + 0.1)) return 1;
            if(isAbovep2(v1t[0] + 0.0, v1t[1] + 0.1) || isAbovep2(v2t[0] + 0.0, v2t[1] + 0.1) || isAbovep2(v3t[0] + 0.0, v3t[1] + 0.1) || isAbovep2(v4t[0] + 0.0, v4t[1] + 0.1)) return 1;
        }
        else if(baixo == 1){
            /*printf("r:\n");
            printf("v1t: %d\n", isAbovep1(v1t[0] + 0.0, v1t[1] - 0.1));
            printf("v2t: %d\n", isAbovep1(v2t[0] + 0.0, v2t[1] - 0.1));
            printf("v3t: %d\n", isAbovep1(v3t[0] + 0.0, v3t[1] - 0.1));
            printf("v4t: %d\n", isAbovep1(v4t[0] + 0.0, v4t[1] - 0.1));

            printf("s:\n");
            printf("v1t: %d\n", isAbovep2(v1t[0] + 0.0, v1t[1] - 0.1));
            printf("v2t: %d\n", isAbovep2(v2t[0] + 0.0, v2t[1] - 0.1));
            printf("v3t: %d\n", isAbovep2(v3t[0] + 0.0, v3t[1] - 0.1));
            printf("v4t: %d\n", isAbovep2(v4t[0] + 0.0, v4t[1] - 0.1));*/

            if(isAbovep1(v1t[0] + 0.0, v1t[1] - 0.1) || isAbovep1(v2t[0] + 0.0, v2t[1] - 0.1) || isAbovep1(v3t[0] + 0.0, v3t[1] - 0.1) || isAbovep1(v4t[0] + 0.0, v4t[1] - 0.1)) return 1;
            if(isAbovep2(v1t[0] + 0.0, v1t[1] - 0.1) || isAbovep2(v2t[0] + 0.0, v2t[1] - 0.1) || isAbovep2(v3t[0] + 0.0, v3t[1] - 0.1) || isAbovep2(v4t[0] + 0.0, v4t[1] - 0.1)) return 1;
        }
        else if(esq == 1){
            /*printf("r:\n");
            printf("v1t: %d\n", isAbovep1(v1t[0] - 0.1, v1t[1] + 0.0));
            printf("v2t: %d\n", isAbovep1(v2t[0] - 0.1, v2t[1] + 0.0));
            printf("v3t: %d\n", isAbovep1(v3t[0] - 0.1, v3t[1] + 0.0));
            printf("v4t: %d\n", isAbovep1(v4t[0] - 0.1, v4t[1] + 0.0));

            printf("s:\n");
            printf("v1t: %d\n", isAbovep2(v1t[0] - 0.1, v1t[1] + 0.0));
            printf("v2t: %d\n", isAbovep2(v2t[0] - 0.1, v2t[1] + 0.0));
            printf("v3t: %d\n", isAbovep2(v3t[0] - 0.1, v3t[1] + 0.0));
            printf("v4t: %d\n", isAbovep2(v4t[0] - 0.1, v4t[1] + 0.0));*/

            if(isAbovep1(v1t[0] - 0.1, v1t[1] + 0.0) || isAbovep1(v2t[0] - 0.1, v2t[1] + 0.0) || isAbovep1(v3t[0] - 0.1, v3t[1] + 0.0) || isAbovep1(v4t[0] - 0.1, v4t[1] + 0.0)) return 1;
            if(isAbovep2(v1t[0] - 0.1, v1t[1] + 0.0) || isAbovep2(v2t[0] - 0.1, v2t[1] + 0.0) || isAbovep2(v3t[0] - 0.1, v3t[1] + 0.0) || isAbovep2(v4t[0] - 0.1, v4t[1] + 0.0)) return 1;
        }
        else if(dir == 1){
            /*printf("r:\n");
            printf("v1t: %d\n", isAbovep1(v1t[0] + 0.1, v1t[1] + 0.0));
            printf("v2t: %d\n", isAbovep1(v2t[0] + 0.1, v2t[1] + 0.0));
            printf("v3t: %d\n", isAbovep1(v3t[0] + 0.1, v3t[1] + 0.0));
            printf("v4t: %d\n", isAbovep1(v4t[0] + 0.1, v4t[1] + 0.0));

            printf("s:\n");
            printf("v1t: %d\n", isAbovep2(v1t[0] + 0.1, v1t[1] + 0.0));
            printf("v2t: %d\n", isAbovep2(v2t[0] + 0.1, v2t[1] + 0.0));
            printf("v3t: %d\n", isAbovep2(v3t[0] + 0.1, v3t[1] + 0.0));
            printf("v4t: %d\n", isAbovep2(v4t[0] + 0.1, v4t[1] + 0.0));*/

            if(isAbovep1(v1t[0] + 0.1, v1t[1] + 0.0) || isAbovep1(v2t[0] + 0.1, v2t[1] + 0.0) || isAbovep1(v3t[0] + 0.1, v3t[1] + 0.0) || isAbovep1(v4t[0] + 0.1, v4t[1] + 0.0)) return 1;
            if(isAbovep2(v1t[0] + 0.1, v1t[1] + 0.0) || isAbovep2(v2t[0] + 0.1, v2t[1] + 0.0) || isAbovep2(v3t[0] + 0.1, v3t[1] + 0.0) || isAbovep2(v4t[0] + 0.1, v4t[1] + 0.0)) return 1;
        }

        break;

    default:
        printf("Error: Invalid object type.\n");
        exit(1);
        break;
    }

    return 0;
}

int isFalling(){

    switch (SELECTED_TYPE)
    {
    case none_type:
        printf("Log: No object selected.\n");
        return 0;
        break;

    case teapot_type:
        printf("Log: teapot falling?.\n");
        double a = 0.14;
        if(DATA.teapot->y != a) return 1;
        else return 0;
        break;

    case sphere_type:
        printf("Log: sphere falling?.\n");
        double b = 0.2;
        if(DATA.sphere->y != b) return 1;
        else return 0;
        break;

    case torus_type:
        printf("Log: torus falling?.\n");
        double c = 0.1;
        if(DATA.torus->y != c) return 1;
        else return 0;
        break;

    default:
        printf("Error: Invalid object type.\n");
        exit(1);
        break;
    }

    return 0;
}

void skeyPressed(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
    {
        printf("Log: Try move to left\n");
        if(verifyColision(1, 0, 0, 0) || isFalling()) printf("Colisao!\n");
        //else if() printf("Caindo!\n");
        else moveObject(0, 0, -1);
    }

    if (key == GLUT_KEY_RIGHT)
    {
        printf("Log: Try move to right\n");
        if(verifyColision(0, 1, 0, 0) || isFalling()) printf("Colisao!\n");
        else moveObject(0, 0, 1);
    }

    if (key == GLUT_KEY_UP)
    {
        printf("Log: Try move to up\n");
        if(verifyColision(0, 0, 0, 1) || isFalling()) printf("Colisao!\n");
        else moveObject(1, 0, 0);
    }

    if (key == GLUT_KEY_DOWN)
    {
        printf("Log: Try move to down\n");
        if(verifyColision(0, 0, 1, 0) || isFalling()) printf("Colisao!\n");
        else moveObject(-1, 0, 0);
    }

    glutPostRedisplay();
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

int isBelow1(double z0, double x0){

    double y;
    double a = -1;
    double b = -1.414;

    y = a*z0 + b;
    if(x0 < y) return 1;

    return 0;

}

int isBelow2(double z0, double x0){

    double y;
    double a = 1;
    double b = -1.414;

    y = a*z0 + b;
    if(x0 < y) return 1;

    return 0;

}

void cair(){

    //y = -x - 1.414

    //calc_eq_reta(0, -1.414214, 1.414214, 0);

    //VERIFICANDO O TEAPOT
    double v1[2] = {DATA.teapot->z+DATA.teapot->hitbox_z+0.13,
                    DATA.teapot->x + DATA.teapot->hitbox_x - 0.13};

    double v2[2] = {DATA.teapot->z-DATA.teapot->hitbox_z-0.13,
                    DATA.teapot->x - DATA.teapot->hitbox_x + 0.13};

    double v3[2] = {DATA.teapot->z-DATA.teapot->hitbox_z-0.13,
                    DATA.teapot->x + DATA.teapot->hitbox_x - 0.13};
    double v4[2] = {DATA.teapot->z+DATA.teapot->hitbox_z+0.13,
                    DATA.teapot->x - DATA.teapot->hitbox_x + 0.13};

    if(isBelow1(v1[0], v1[1]) && isBelow1(v2[0], v2[1]) && isBelow1(v3[0], v3[1]) && isBelow1(v4[0], v4[1])) DATA.teapot->y-=0.1;
    else if(isBelow2(v1[0], v1[1]) && isBelow2(v2[0], v2[1]) && isBelow2(v3[0], v3[1]) && isBelow2(v4[0], v4[1])) DATA.teapot->y-=0.1;
    else if(v1[1] < -1.414214 && v2[1] < -1.414214 && v3[1] < -1.414214 && v4[1] < -1.414214) DATA.teapot->y-=0.1;

    //VERIFICANDO ESFERA
    double v1s[2] = {DATA.sphere->z+DATA.sphere->hitbox_z,
                    DATA.sphere->x + DATA.sphere->hitbox_x};

    double v2s[2] = {DATA.sphere->z-DATA.sphere->hitbox_z,
                    DATA.sphere->x - DATA.sphere->hitbox_x};

    double v3s[2] = {DATA.sphere->z-DATA.sphere->hitbox_z,
                    DATA.sphere->x + DATA.sphere->hitbox_x};

    double v4s[2] = {DATA.sphere->z+DATA.sphere->hitbox_z,
                    DATA.sphere->x - DATA.sphere->hitbox_x};

    if(isBelow1(v1s[0], v1s[1]) && isBelow1(v2s[0], v2s[1]) && isBelow1(v3s[0], v3s[1]) && isBelow1(v4s[0], v4s[1])) DATA.sphere->y-=0.1;
    else if(isBelow2(v1s[0], v1s[1]) && isBelow2(v2s[0], v2s[1]) && isBelow2(v3s[0], v3s[1]) && isBelow2(v4s[0], v4s[1])) DATA.sphere->y-=0.1;
    else if(v1s[1] < -1.414214 && v2s[1] < -1.414214 && v3s[1] < -1.414214 && v4s[1] < -1.414214) DATA.sphere->y-=0.1;

    //VERIFICANDO TORUS
    double v1t[2] = {DATA.torus->z+DATA.torus->hitbox_z + 0.2,
                    DATA.torus->x + DATA.torus->hitbox_x};

    double v2t[2] = {DATA.torus->z-DATA.torus->hitbox_z - 0.2,
                    DATA.torus->x - DATA.torus->hitbox_x};

    double v3t[2] = {DATA.torus->z-DATA.torus->hitbox_z - 0.2,
                    DATA.torus->x + DATA.torus->hitbox_x};

    double v4t[2] = {DATA.torus->z+DATA.torus->hitbox_z + 0.2,
                    DATA.torus->x - DATA.torus->hitbox_x};

    if(isBelow1(v1t[0], v1t[1]) && isBelow1(v2t[0], v2t[1]) && isBelow1(v3t[0], v3t[1]) && isBelow1(v4t[0], v4t[1])) DATA.torus->y-=0.1;
    else if(isBelow2(v1t[0], v1t[1]) && isBelow2(v2t[0], v2t[1]) && isBelow2(v3t[0], v3t[1]) && isBelow2(v4t[0], v4t[1])) DATA.torus->y-=0.1;
    else if(v1t[1] < -1.414214 && v2t[1] < -1.414214 && v3t[1] < -1.414214 && v4t[1] < -1.414214) DATA.torus->y-=0.1;
}


