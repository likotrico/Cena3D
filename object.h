#ifndef OBJECT_H
#define OBJECT_H

// TEAPOT

#define teapot_hitbox_x 1.7
#define teapot_hitbox_y 0.7
#define teapot_hitbox_z 1

typedef struct
{
    double x;
    double y;
    double z;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
    double size;
} Teapot;

Teapot *createTeapot(double, double, double, double);

void moveTeapot(Teapot *, double, double, double);

// SPHERE

#define sphere_hitbox_x 1
#define sphere_hitbox_y 1
#define sphere_hitbox_z 1

typedef struct
{
    double x;
    double y;
    double z;
    double radius;
    int slices;
    int stacks;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
} Sphere;

Sphere *createSphere(double, double, double, double, int, int);

void moveSphere(Sphere *, double, double, double); 

// TORUS

typedef struct
{
    double x;
    double y;
    double z;
    double innerRadius;
    double outerRadius;
    int sides;
    int rings;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
} Torus;

Torus *createTorus(double, double, double, double, double, int, int);

void moveTorus(Torus *, double, double, double); 

// BLOCK

typedef struct
{
    double x;
    double y;
    double z;
    double hitbox_x;
    double hitbox_y;
    double hitbox_z;
} Block;

Block *createBlock(double, double, double, double, double, double);

void moveBlock(Block *, double, double, double); 

// DATA

typedef enum type
{
    none_type = 0,
    teapot_type,
    sphere_type,
    torus_type
} Type;

typedef struct data
{
    Teapot *teapot;
    Sphere *sphere;
    Torus *torus;
} Data;

extern Type SELECTED_TYPE;
extern Data DATA;

void initData();

#endif
