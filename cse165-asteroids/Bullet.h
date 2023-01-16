#ifndef Bullet_h
#define Bullet_h

#include "Ship.h"
#include <math.h>
#include "GlutApp.h"
#include "Rock.h"

class Bullet: public Ship {

public:
    bool hit;

    bool shot;

    bool dead;

    Bullet();
    
    Bullet(float, float, float, float);

    Bullet(float, float, float, float, float, float, float);

    void moveLeft();

    bool getDead();

    void setDead(bool);

    void shoot();

    void autoMove();

    void setShot(bool);

    bool getShot();

};

#endif
