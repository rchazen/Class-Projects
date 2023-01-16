#include "Bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet(){
	x = getX();   //spawn bullet at the same spot as the ship
	y = getY();

	//Pink: HEX FF0080
	red = 1;
	green = 0;
	blue = 0.52;

	w = 0.01;
	h = 0.06;

    hit = false;

	shot = false;

	dead = false;
	
}

Bullet::Bullet(float x, float y, float w, float h){
	this->x = getX();  //bullet should move with the ship
	this->y = getY();

	this->w = 0.1;
	this->h = 0.2;

    hit = false;
}

Bullet::Bullet(float x, float y, float w, float h, float red, float green, float blue){
	this->x = getX();;
	this->y = getY();

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;

    hit = false;
}

/*void Bullet::draw(){

	glColor3f(red, green, blue);
	
	glBegin(GL_LINE_LOOP);
    double radius = 0.02;
    double ori_x = 0.0;
    double ori_y = 0.0;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * M_PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();
	
}*/

bool Bullet::getShot(){
	return shot;
}
void Bullet::setShot(bool b){
	shot = b;
}

bool Bullet::getDead(){
    return dead;
}

void Bullet::setDead(bool b){
    dead = b;
} 

void Bullet::moveLeft(){
	if(x < -1.5 ){
		setShot(false);
		setDead(true);
	}
	x -= 0.05;
    setX(x);
	glutPostRedisplay(); 
}

void Bullet::autoMove(){
	moveLeft();
	glTranslatef(getX(),getY(),0);
	draw();
}

void Bullet::shoot(){

		x = getX();
		autoMove();

}
