#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Bullet.h"
#include "Ship.h"
#include "Rock.h"
#include <vector>

using namespace std;
class App: public GlutApp {

    Bullet* bullet;
    Ship* ship;
    //Rock* rock;
    vector<Rock> rock;
//    Rock* rock1;
//    Rock* rock2;
//    Rock* rock3;
//    Rock* rock4;
    
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void startRocks();
    void theRock();
    
    void draw();
    void drawTheRock();

    bool collision(Ship &one, Rock& two);
    bool collision(Bullet &one, Rock& two);

        
    void DoCollisions();
        
    void Update();
    
    void keyDown(unsigned char key, float x, float y);

    ~App();
    
};

#endif
