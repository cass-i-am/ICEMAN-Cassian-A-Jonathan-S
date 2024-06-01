#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


class Actor : public GraphObject{
public:

    Actor(int imageID, int startx, int starty, Direction dir, StudentWorld* world, double size, unsigned int depth);

}; 

// Charachters 

class Protester: public Actor {
public:
    Protester(int ImageID, int startX, int startY, Direction dir, double size, unsigned int dept) : Actor(ImageID, startX, startY, dir, size, depth){
        setVisibility(true);
    }

};


class HardcoreProtester: public Protester {
public: 
    HardcoreProtester(int startX, int startY): Protester(IID_HARD_CORE_PROTESTER, startX, startY, left, 1, 0){
        setVisibility(true); 
    }
 
};

class Iceman : public Actor {
public:
    Iceman(int startX, int startY): Actor(IID_PLAYER, startX, startY, right, 1, 0){
        setVisibility(true);
    }

    virtual void doSomething() override {
        int ch;
        if(getWorld()->getKey(ch)){
            switch(ch){
                case KEY_PRESS_LEFT:
                    if(getDirection() == left){
                        if(getX() > 0){
                            moveTo(getX() - 1, getY());
                        }
                    } else {
                        setDirection(left);
                    }
                    break;
                case KEY_PRESS_RIGHT:
                    if(getDirection() == right){
                        if(getX() < 60){
                            moveTo(getX() + 1, getY());
                        }
                    } else {
                        setDirection(right);
                    }
                    break;
                case KEY_PRESS_UP:
                    if(getDirection() == up){
                        if(getY() < 60){
                            moveTo(getX(), getY() + 1);
                        }
                    } else {
                        setDirection(up);
                    }
                    break;
                case KEY_PRESS_DOWN:
                    if(getDirection() == down){
                        if(getY() > 0){
                            moveTo(getX(), getY() - 1);
                        }
                    } else {
                        setDirection(down);
                    }
                    break;
                case KEY_PRESS_SPACE:
                    // Shoot
                    break;
                case KEY_PRESS_ESCAPE:
                    // Quit
                    break;
            }
        }
    }

};
}


// Game Objects


class Ice : public GraphObject {
public:
    Ice(int startX, StartY): GraphObject(IID_ICE, startX, startY, right, 0.9, .3){
        setVisible(true);
    }

    virtual void doSomething() override {

    }

};




class GoldNugget : public GraphObject{
public:
    GoldNugget(int startX, int startY, bool isPermanent): GraphObject (IID_GLD, startX, startY, right, 1, 2){
        setVisibility(true);
        m_isPermanent = isPermanent; 
    }
};

class OilBarrel : public GraphObject {
public:
    OIlBarrel(int startX, int startY): GraphObject(IID_OIL_BARREL, startX, startY, right, 1, 2){
        setVisibility(true);
    }

};





#endif // ACTOR_H_
