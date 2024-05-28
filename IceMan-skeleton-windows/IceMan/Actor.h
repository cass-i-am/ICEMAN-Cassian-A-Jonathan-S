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

};


class HardcoreProtester: public Protester {
public: 

};


// Game Objects


class Ice : public GraphObject {
public:
    Ice(int startX, StartY): GraphObject(IID_ICE, startX, startY, right, 0.9, .3){
        setVisible(true);
    }

    virtual void doSomething() override {
        //ice does something;
        // setVisibility(IID_ICE) = true; 
    }

};




class GoldNugget : public GraphObject{
public:

};

class OilBarrel : public GraphObject {
public:

};





#endif // ACTOR_H_
