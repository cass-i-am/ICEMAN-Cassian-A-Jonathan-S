#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Forward declaration of StudentWorld
class StudentWorld;

class Actor : public GraphObject {
public:
    Actor(int imageID, int startX, int startY, Direction dir, StudentWorld* world, double size = 1.0, unsigned int depth = 0);
    virtual void doSomething() = 0; // pure virtual function making Actor an abstract class
    virtual bool isAlive() const { return alive; }
    virtual void setDead() { alive = false; }
    virtual ~Actor() = 0; // pure virtual destructor to make the class abstract

protected:
    StudentWorld* getWorld() const { return m_world; }

private:
    bool alive;
    StudentWorld* m_world;
};

inline Actor::~Actor() {} // Provide a definition for the pure virtual destructor

class Iceman : public Actor {
public:
    Iceman(int startX, int startY, StudentWorld* world);
    virtual void doSomething() override;
};

class Protester : public Actor {
public:
    Protester(int imageID, int startX, int startY, StudentWorld* world, Direction dir = left, double size = 1.0, unsigned int depth = 0);
    virtual void doSomething() override = 0; // Protester is abstract
};

class HardcoreProtester : public Protester {
public: 
    HardcoreProtester(int startX, int startY, StudentWorld* world);
    virtual void doSomething() override;
};

class Ice : public Actor {
public:
    Ice(int startX, int startY, StudentWorld* world);
    virtual void doSomething() override;
};

class GoldNugget : public Actor {
public:
    GoldNugget(int startX, int startY, bool isPermanent, StudentWorld* world);
    virtual void doSomething() override;

private:
    bool m_isPermanent;
};

class OilBarrel : public Actor {
public:
    OilBarrel(int startX, int startY, StudentWorld* world);
    virtual void doSomething() override;
};

#endif // ACTOR_H_
