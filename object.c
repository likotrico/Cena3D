#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "object.h"

Type SELECTED_TYPE = none_type;
Data DATA = {NULL, NULL, NULL};

void initData()
{
    free(DATA.teapot);
    free(DATA.sphere);
    free(DATA.teapot);

    DATA.teapot = createTeapot(-5, 0, 5, 2.5);
    DATA.sphere = createSphere(5, 0, 5, 2.5, 100, 5);
    DATA.torus = createTorus(-5, 0, -5, 0.5, 2.5, 100, 20);
}

void freeData()
{
    free(DATA.teapot);
    free(DATA.sphere);
    free(DATA.teapot);
}

Teapot *createTeapot(double x, double y, double z, double s)
{
    Teapot *teapot;
    teapot = (Teapot *)malloc(sizeof(Teapot));
    teapot->x = x;
    teapot->y = y;
    teapot->z = z;
    teapot->teapot_size = s;
    teapot->hitbox_x = 0 + teapot_hitbox_x*teapot->teapot_size;
    teapot->hitbox_y = 0 + teapot_hitbox_y*teapot->teapot_size;
    teapot->hitbox_z = 0 + teapot_hitbox_z*teapot->teapot_size;

    return teapot;
}

void moveTeapot(Teapot *teapot, double x, double y, double z)
{
    teapot->x += x;
    teapot->y += y;
    teapot->z += z;
    teapot->hitbox_x = teapot->x + teapot_hitbox_x;
    teapot->hitbox_y = teapot->y + teapot_hitbox_y;
    teapot->hitbox_z = teapot->z + teapot_hitbox_z;
}

void setTeapot(Teapot *teapot, double x, double y, double z)
{
    teapot->x = x;
    teapot->y = y;
    teapot->z = z;
    teapot->hitbox_x = x + teapot_hitbox_x;
    teapot->hitbox_y = y + teapot_hitbox_y;
    teapot->hitbox_z = z + teapot_hitbox_z;
}

Sphere *createSphere(double x, double y, double z, double radius, int slices, int stacks)
{
    Sphere *sphere;
    sphere = (Sphere *)malloc(sizeof(Sphere));
    sphere->x = x;
    sphere->y = y;
    sphere->z = z;
    sphere->radius = radius;
    sphere->slices = slices;
    sphere->stacks = stacks;

    sphere->hitbox_x = x + sphere_hitbox_x * sphere->radius;
    sphere->hitbox_y = y + sphere_hitbox_y * sphere->radius;
    sphere->hitbox_z = z + sphere_hitbox_z * sphere->radius;

    return sphere;
}

void moveSphere(Sphere *sphere, double x, double y, double z)
{
    sphere->x += x;
    sphere->y += y;
    sphere->z += z;
    sphere->hitbox_x = sphere->x + sphere_hitbox_x;
    sphere->hitbox_y = sphere->y + sphere_hitbox_y;
    sphere->hitbox_z = sphere->z + sphere_hitbox_z;
}

void setSphere(Sphere *sphere, double x, double y, double z)
{
    sphere->x = x;
    sphere->y = y;
    sphere->z = z;
    sphere->hitbox_x = x + sphere_hitbox_x;
    sphere->hitbox_y = y + sphere_hitbox_y;
    sphere->hitbox_z = z + sphere_hitbox_z;
}

Torus *createTorus(double x, double y, double z, double innerRadius, double outerRadius, int sides, int rings)
{
    Torus *torus;
    torus = (Torus *)malloc(sizeof(Torus));
    torus->x = x;
    torus->y = y;
    torus->z = z;
    torus->innerRadius = innerRadius;
    torus->outerRadius = outerRadius;
    torus->sides = sides;
    torus->rings = rings;

    torus->hitbox_x = torus->x + torus->outerRadius + torus->innerRadius;
    torus->hitbox_y = torus->y + torus->outerRadius + torus->innerRadius;
    torus->hitbox_z = torus->z + torus->innerRadius;

    return torus;
}

void moveTorus(Torus *torus, double x, double y, double z)
{
    torus->x += x;
    torus->y += y;
    torus->z += z;

    torus->hitbox_x = torus->x + torus->outerRadius + torus->innerRadius;
    torus->hitbox_y = torus->y + torus->outerRadius + torus->innerRadius;
    torus->hitbox_z = torus->z + torus->innerRadius;
}

void setTorus(Torus *torus, double x, double y, double z)
{
    torus->x = x;
    torus->y = y;
    torus->z = z;

    torus->hitbox_x = torus->x + torus->outerRadius + torus->innerRadius;
    torus->hitbox_y = torus->y + torus->outerRadius + torus->innerRadius;
    torus->hitbox_z = torus->z + torus->innerRadius;
}

Block *createBlock(double x, double y, double z, double hitbox_x, double hitbox_y, double hitbox_z)
{
    Block *block;
    block = (Block *)malloc(sizeof(Block));
    block->x = x;
    block->y = y;
    block->z = z;
    block->hitbox_x = hitbox_x;
    block->hitbox_y = hitbox_y;
    block->hitbox_z = hitbox_z;

    return block;
}

Sphere *createSphere(double x, double y, double z, double radius, int slices, int stacks){ //x, y, z, radius, slices, stacks
    Sphere *sphere;
    sphere = (Sphere*)malloc(sizeof(Sphere));
    sphere->x = x;
    sphere->y = y;
    sphere->z = z;
    sphere->radius = radius;
    sphere->slices = slices;
    sphere->stacks = stacks;

    sphere->hitbox_x = sphere_hitbox_x*sphere->radius;
    sphere->hitbox_y = sphere_hitbox_y*sphere->radius;
    sphere->hitbox_z = sphere_hitbox_z*sphere->radius;

    return sphere;
}

void moveSphere(Sphere *sphere, double newX, double newY, double newZ){
    sphere->x = newX;
    sphere->y = newY;
    sphere->z = newZ;
    //sphere->hitbox_x = newX + sphere_hitbox_x;
    //sphere->hitbox_y = newY + sphere_hitbox_y;
    //sphere->hitbox_z = newZ + sphere_hitbox_z;
}

Torus *createTorus(double x, double y, double z, double innerRadius, double outerRadius, int nsides, int rings){ //x, y, z, innerRadius, outerRadius, nsides, rings
    Torus *torus;
    torus = (Torus*)malloc(sizeof(Torus));
    torus->x = x;
    torus->y = y;
    torus->z = z;
    torus->innerRadius = innerRadius;
    torus->outerRadius = outerRadius;
    torus->nsides = nsides;
    torus->rings = rings;

    torus->hitbox_x = torus->outerRadius + torus->innerRadius;
    torus->hitbox_y = torus->outerRadius + torus->innerRadius;
    torus->hitbox_z = torus->innerRadius;

    return torus;
}

void moveTorus(Torus *torus, double newX, double newY, double newZ){
    torus->x = newX;
    torus->y = newY;
    torus->z = newZ;

    torus->hitbox_x = torus->x + torus->outerRadius + torus->innerRadius;
    torus->hitbox_y = torus->y + torus->outerRadius + torus->innerRadius;
    torus->hitbox_z = torus->z + torus->innerRadius;
}

Block *createBlock(double x, double y, double z, double hitbox_x, double hitbox_y, double hitbox_z){
    Block *block;
    block = (Block*)malloc(sizeof(Block));
    block->x = x;
    block->y = y;
    block->z = z;
    block->hitbox_x = hitbox_x;
    block->hitbox_y = hitbox_y;
    block->hitbox_z = hitbox_z;

    return block;
}
