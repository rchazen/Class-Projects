#include <iostream>
#include <time.h>
#include "App.h"
#include <vector>

using namespace std;

App::App(int argc, char** argv, int width, int height, const char* title) : GlutApp(argc, argv, width, height, title){
    
    //rock = new Rock[]
    bullet = new Bullet();
    ship = new Ship();
    rock.push_back();
//    rock1 = new Rock(0.1, 0, 0.4, 0.2, 0.2, 1);   //(radius, x, y)
//    rock2 = new Rock(0.1, 0, -1, 0, 1, 0.2);
//    rock3 = new Rock(0.1, 0, 1.3,0.5,0.3,0.1);
//    rock4 = new Rock(0.1, 0, -1.55,0,1,0.75);
}
//occupy the space with objects
void App::draw() {
    
    ship->draw();
    bullet->draw();
    startRocks();
    //drawTheRock();
  

}
//void App::drawTheRock(){
//    
//}

//constant functions to call when start of program
//void App::theRock(){
//    rock->autoMoveTheRock();
//}
void App::startRocks(){
    //rock->autoMove();
    rock ->autoMove();
//    rock1->autoMove();
//    rock2->autoMove();
//    rock3->autoMove();
//    rock4->autoMove();
    this->DoCollisions();
    if(bullet->getShot() == true){
        bullet->autoMove();
        if(bullet->getDead() == true){
            delete bullet;
            bullet = new Bullet();
            bullet->setX(ship->getX());
            bullet->setY(ship->getY());
        }
    }
}

void App::Update(){
    
    this->DoCollisions();
    //cout << "test" << endl;
}
bool App::collision(Ship &ship, Rock &rock){
    //cout << "accessed" << endl;
    bool collisionX = (ship.getX()+ship.getW()) >= rock.getX()-rock.getRadius()*2 && rock.getX() + rock.getRadius()*6 >= ship.getX();
    
    bool collisionY = ship.getY()+ship.getH() >= rock.getY() && rock.getY() + rock.getRadius()*2 >= ship.getY();
    return collisionX && collisionY;
}
bool App::collision(Bullet &ship, Rock &rock){
    //cout << "accessed" << endl;
    bool collisionX = (ship.getX()+ship.getW()) >= rock.getX()-rock.getRadius()*2 && rock.getX() + rock.getRadius()*2 >= ship.getX();
    
    bool collisionY = ship.getY()+ship.getH() >= rock.getY()-rock.getRadius() && rock.getY() + rock.getRadius() >= ship.getY();
    return collisionX && collisionY;
}
void App::DoCollisions(){
    //cout << "accessed111" << endl;
    for(int i =0;i<5;i++){
        if(collision(*ship, *rock[i])){
            //cout << "HIT!!!!!!!!!!";
            ship->isHit();
        }
    }
    if(collision(*bullet, *rock)){
       
       //|| collision(*bullet, *rock1) || collision(*bullet, *rock2) || collision(*bullet, *rock3) || collision(*bullet, *rock4)){
        rock.setY(rock->isHit());
        rock.setX(-2);
    }
    
}


//closes app
void App::keyDown(unsigned char key, float x, float y){
    
    if(key == 'p'){
        exit(0);
    }
    if(key == 's'){
        (*ship).moveDown();
        ship->moveDown();
        if(bullet->getShot() == false){
            (*bullet).moveDown();
            bullet->moveDown();
        }
        
    }
    if(key == 'w'){
        (*ship).moveUp();
        ship->moveUp();
        if(bullet->getShot() == false){
            (*bullet).moveUp();
            bullet->moveUp();
        }
    }
    if(key == ' '){
        (*bullet).shoot();
        bullet->shoot();
        bullet->setShot(true);
        float bulletX = (*bullet).getX();
        float bulletY = (*bullet).getY();
        /*if((*alien).contains(bulletX, bulletY)){
            delete alien;
        }*/
    }

    redraw();

}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    delete ship;
    delete bullet;
    //delete rock;
}
