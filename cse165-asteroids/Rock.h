#ifndef Rock_h
#define Rock_h

class Rock{
protected:
    float xPos;
    float yPos;
    float radius;
    float x;
    float y;

    float red;
    float green;
    float blue;


public:
    Rock();
    Rock(float, float, float);
    Rock(float, float, float, float, float, float);
    Rock(const Rock&);
    bool operator== (const Rock&);
    ~Rock();

    void draw();
    double  isHit();
    float getRadius() const;
    float getX() const;
	float getY() const;
	float getR() const;
	float getG() const;
	float getB() const;
	void setX(float x);
	void setY(float y);
	void setRadius(float rd);
    void drawTheRock();
    void autoMoveTheRock();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void autoMove();
};
#endif
