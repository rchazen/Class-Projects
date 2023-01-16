#include <iostream>
#include <math.h>
#include <cstring>
#include "Ship.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

Ship::Ship(){
	//bullet = new Bullet();
	x = 1.55;
	y = 0.1;
	red = 1;
	green = 1;
	blue = 1;

	w = 0.2;
	h = 0.2;
}

Ship::Ship(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 1;

	this->w = w;
	this->h = h;
}

Ship::Ship(float x, float y, float w, float h, float red, float green, float blue){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;
}

Ship::Ship(const Ship& other){
	x = other.x;
	y = other.y;

	red = other.red;
	green = other.green;
	blue = other.blue;

	w = other.w;
	h = other.h;
}

bool Ship::operator== (const Ship& other){
	return 	x == other.x && 
			y == other.y && 
			h == other.h && 
			red == other.red && 
			green == other.green && 
			blue == other.blue;
}

Ship::~Ship(){}

bool Ship::contains(float x, float y) const {
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}


void Ship::draw(){

	glColor3f(red, green, blue);
	
	glBegin(GL_LINES);   //see through triangle

	glVertex2f(x, y);
	glVertex2f(x+w, y-(h/2));

	glVertex2f(x+w,y-(h/2));
    glVertex2f(x+w,y+(h/2));
	
    glVertex2f(x+w,y+(h/2));
	glVertex2f(x, y);

	glEnd();

	/*glBegin(GL_POLYGON);   //solid triangle 

	glVertex2f(x, y);
	glVertex2f(x+(w/2), (y-h));
    glVertex2f(x-(w/2), (y-h));

	glEnd();*/
	
}

void Ship::displayEnd(){

	int len;
	int i = 0;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	char string[] = "GAME OVER";
	len = (int)strlen(string);
	glColor3f(red, green, blue);
	glRasterPos2f(0, 0);

	while(i < 2){
		glRasterPos2f(-1.5, 0);
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
		}
	}

}

bool Ship::isHit(){
	displayEnd();
	exit(0);
    return true;
}


float Ship::getX() const {
	return x;
}

float Ship::getY() const {
	return y;
}

float Ship::getW() const {
	return w;
}

float Ship::getH() const {
	return h;
}

float Ship::getR() const {
	return red;
}

float Ship::getG() const {
	return green;
}

float Ship::getB() const {
	return blue;
}

void Ship::setX(float x){
	this->x = x;
}

void Ship::setY(float y){
	this->y = y;
}

void Ship::setW(float w){
	this->w = w;
}

void Ship::setH(float h){
	this->h = h;
}

void Ship::moveUp(){
	y += 0.05;
	setY(y);
}

void Ship::moveDown(){
	y -= 0.05;
	setY(y);
}

void Ship::moveLeft(){
	x -= 0.05;
	setX(x);
}

void Ship::moveRight(){
	x += 0.05;
	setX(x);
}
