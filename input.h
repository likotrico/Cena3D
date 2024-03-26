#ifndef INPUT_H
#define INPUT_H

#define SPEED 0.1

extern int HITBOX_ON;

void keyPressed(unsigned char, int, int);
void skeyPressed(int, int, int);

void moveObject(double, double, double);
void cair();

#endif
