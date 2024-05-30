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
