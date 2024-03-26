#ifndef PHYSICS_H
#define PHYSICS_H

int verifyCollision(int, int, int, int);

int isFalling();
void fall();

double *calc_eq_reta(double, double, double, double);

int isAbove1(double, double);
int isAbove2(double, double);
int isBelow1(double, double);
int isBelow2(double, double);

#endif
