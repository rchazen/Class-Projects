#ifndef Ship_H
#define Ship_H

//#inlcude "Bullet.h"

class Ship {
protected:

	//Bullet bullet;
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float w;
	float h;

    bool hit;

public:
	Ship();

	Ship(float, float, float, float);

	Ship(float, float, float, float, float, float, float);

	Ship(const Ship&);

	bool operator== (const Ship&);

	~Ship();

	void draw();

	bool contains(float, float) const;
	void displayEnd();
    bool isHit();

	float getX() const;
	float getY() const;
	float getW() const;
	float getH() const;
	float getR() const;
	float getG() const;
	float getB() const ;
	void setX(float x);
	void setY(float y);
	void setW(float w);
	void setH(float h);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

};

#endif
