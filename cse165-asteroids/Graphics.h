#ifndef Graphics_H
#define Graphics_H

#if defined WIN32
#include <freeglut.h>
#include "../SOIL/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include "SOIL/inc/SOIL/SOIL.h"
#else
#include <GL/freeglut.h>
#include "SOIL/inc/SOIL/SOIL.h"
#endif

#include <vector>

class Graphics{

int width;
int height;
int score;
GLuint score_id;
GLuint background_id;

void setBackDisp(const char*);
void displayBackground();

public:

Graphics(int,int);

Graphics(const char*, const char*, const char*, int, int);

~Graphics();

void draw();

void movePlatform(float);

void collision();

float getShipSpeed() const;

void setShipspeed(float);

};
#endif
