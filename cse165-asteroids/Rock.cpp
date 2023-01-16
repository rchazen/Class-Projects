#include <math.h>
#include "Rock.h"
#include <time.h>
#include <random>
#include <iostream>
using namespace std;

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Rock::Rock(){
    time_t t;
	xPos = -2.0;
	yPos = 0.5;
    radius = 0.1;
	x = -2.0;
	y = 0.1;
	red = 1;
	green = 1;
	blue = 1;
    srand((unsigned) time (&t));

}

Rock::Rock(float radius, float x, float y){
	xPos = -2;
	yPos = 0.5;
	this->radius = radius;
    this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 1;
    time_t t;

    srand((unsigned) time (&t));
}

Rock::Rock(float radius, float x, float y, float r, float g, float b){
	xPos = -2;
	yPos = 0.5;
	this->radius = radius;
    this->x = x;
	this->y = y;

	red = r;
	green = g;
	blue = b;
    time_t t;

    srand((unsigned) time (&t));
}

Rock::Rock(const Rock& other){
	xPos = other.xPos;
	yPos = other.yPos;
    radius = other.radius;
	x = other.x;
	y = other.y;

	red = other.red;
	green = other.green;
	blue = other.blue;

}

bool Rock::operator== (const Rock& other){
	return 	radius == other.radius &&
			xPos == other.xPos &&
			yPos == other.yPos &&
            x == other.x && 
			y == other.y && 
			red == other.red && 
			green == other.green && 
			blue == other.blue;
}

Rock::~Rock(){}

void Rock::draw(){

    // glLoadIdentity();
    // counter=counter-0.05;
    // glTranslated(counter, 100, 0.0);
    glColor3f(red,green,blue);
	glBegin(GL_LINE_LOOP);                        // Middle circle
    double radius = 0.1;
    double ori_x = 0.5;                         // the origin or center of circle
    double ori_y = 0.0;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * M_PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
	
}
void Rock::drawTheRock(){
    glColor3f(red,green,blue);
    glBegin(GL_LINE_LOOP);                        // Middle circle
    double radius = 0.1;
    double ori_x = 0.5;                         // the origin or center of circle
    double ori_y = 0.0;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * M_PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
}

// void display(){
//     glClear(GL_COLOR_BUFFER_BIT);
//     draw();
//     glutSwapBuffers();
//     glFlush();
// }

float Rock::getX() const {
	return x;
}

float Rock::getY() const {
	return y;
}

float Rock::getRadius() const {
	return radius;
}

float Rock::getR() const {
	return red;
}

float Rock::getG() const {
	return green;
}

float Rock::getB() const {
	return blue;
}

void Rock::setX(float x){
	this->x = x;
}

void Rock::setY(float y){
	this->y = y;
}

void Rock::setRadius(float rd){
	this->radius = radius;
}

/**
void Rock::moveLeft(){
	x -= 0.05;
	setX(x);
}
**/
double Rock::isHit(){
     double MIN = -0.5;
     double MAX = 0.5;
    time_t t;
    double rand_num = MIN + (double)(rand()) / ((double)(RAND_MAX/(MAX - MIN)));
    srand((unsigned) time (&t));

    //s//etX(this->x = -2);
    return rand_num;
    cout << rand_num << endl;
    //setY(this->y = rand_num);
}
void Rock::moveRight(){
	if(this->x<=1.5){
		setX(this->x+=0.012);
	}
	else{
		setX(this->x-2.5);
	}
	glutPostRedisplay(); 
}
//void Rock::autoMoveTheRock(){
//    moveRight();
//    glTranslatef(getX(),getY(),0);
//    drawTheRock();
//}

void Rock::autoMove(){
	moveRight();
	glTranslatef(getX(),getY(),0);
	draw();
}
