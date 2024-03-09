#ifndef OBJECT_H
#define OBJECT_H

//A HITBOX É SETADA NA FUNÇÃO CREATE

#define teapot_hitbox_x 1.7
#define teapot_hitbox_y 0.7
#define teapot_hitbox_z 1

typedef struct{
    double x;
    double y;
    double z;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
    double teapot_size;
} Teapot;

Teapot *createTeapot(double, double, double, double); //x, y, z, size

void moveTeapot(Teapot *, double, double, double); //newX, newY, newZ

#define sphere_hitbox_x 1
#define sphere_hitbox_y 1
#define sphere_hitbox_z 1

typedef struct{
    double x;
    double y;
    double z;
    double radius;
    int slices;
    int stacks;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
}Sphere;

Sphere *createSphere(double, double, double, double, int, int); //x, y, z, radius, slices, stacks

void moveSphere(Sphere *, double, double, double); //newX, newY, newZ


typedef struct{
    double x;
    double y;
    double z;
    double innerRadius;
    double outerRadius;
    int nsides;
    int rings;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
}Torus;

Torus *createTorus(double, double, double, double, double, int, int); //x, y, z, innerRadius, outerRadius, nsides, rings

void moveTorus(Torus *, double, double, double); //newX, newY, newZ

typedef struct{
    double x;
    double y;
    double z;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
}Block;

Block *createBlock(double, double, double, double, double, double); //x, y, z, x_expansion, y_expansion, z_expansion

void moveBlock(Block *, double, double, double); //newX, newY, newZ

#endif
