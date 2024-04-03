#ifndef INPUT_H
#define INPUT_H

#define INC_Z .05
#define MIN_Z -19
#define MAX_Z 20

extern int HITBOX_ON;
extern int WIRE_ON;
extern int ZOOM;

void keyPressed(unsigned char, int, int);
void skeyPressed(int, int, int);

void moveObject(double, double, double);

#endif
