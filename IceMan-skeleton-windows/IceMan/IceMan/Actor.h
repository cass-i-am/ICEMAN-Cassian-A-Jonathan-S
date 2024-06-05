#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class Actor : public GraphObject {
public:
    Actor(int img_ID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) 
        : GraphObject(img_ID, startX, startY, dir, size, depth) {}

    void doSomething() {}
};

class Player : public Actor {
private:
    int hp;
    int sonar;
    int gold;

public:
    Player(int img_ID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) 
        : Actor(img_ID, startX, startY, dir, size, depth) 
    {
        hp = 10;
        sonar = 1;
        gold = 0;
    }

    virtual void doSomething() {}
};

class Protester : public Actor {
public:
    virtual void doSomething() {}
};

class IceBlock : public Actor {
public:
    IceBlock(int img_ID, int startX, int startY, Direction dir = right, double size = 0.25, unsigned int depth = 3) 
        : Actor(img_ID, startX, startY, dir, size, depth) {}

    virtual void doSomething() {}
};

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

#endif // ACTOR_H_