#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "object.h"


Teapot *createTeapot(double x, double y, double z, double s){
    Teapot *teapot;
    teapot = (Teapot*)malloc(sizeof(Teapot));
    teapot->x = x;
    teapot->y = y;
    teapot->z = z;
    teapot->teapot_size = s;
    teapot->hitbox_x = x + teapot_hitbox_x*teapot->teapot_size;
    teapot->hitbox_y = y + teapot_hitbox_y*teapot->teapot_size;
    teapot->hitbox_z = z + teapot_hitbox_z*teapot->teapot_size;

    return teapot;
}

void moveTeapot(Teapot *teapot, double newX, double newY, double newZ){
    teapot->x = newX;
    teapot->y = newY;
    teapot->z = newZ;
    teapot->hitbox_x = newX + teapot_hitbox_x;
    teapot->hitbox_y = newY + teapot_hitbox_y;
    teapot->hitbox_z = newZ + teapot_hitbox_z;
}
