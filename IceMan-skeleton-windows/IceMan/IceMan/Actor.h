#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;  // Forward declaration

// Base class for all actors
class Actor : public GraphObject {
public:
    Actor(int img_ID, int startX, int startY, Direction dir = right, double size = 1.0, unsigned int depth = 0) 
        : GraphObject(img_ID, startX, startY, dir, size, depth), m_alive(true) {}

    virtual void doSomething() = 0; // Pure virtual function to ensure all actors implement it
    bool isAlive() const { return m_alive; }
    void setDead() { m_alive = false; }

    virtual ~Actor() {}

private:
    bool m_alive;
};

// Iceman (Player) class
class Iceman : public Actor {
public:
    Iceman(int startX, int startY)
        : Actor(IID_PLAYER, startX, startY, right, 1, 0), hp(10), sonar(1), gold(0) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        int ch;
        if (getWorld()->getKey(ch)) {
            switch (ch) {
                case KEY_PRESS_LEFT:
                    if (getDirection() == left) {
                        if (getX() > 0) {
                            moveTo(getX() - 1, getY());
                        }
                    } else {
                        setDirection(left);
                    }
                    break;
                case KEY_PRESS_RIGHT:
                    if (getDirection() == right) {
                        if (getX() < 60) {
                            moveTo(getX() + 1, getY());
                        }
                    } else {
                        setDirection(right);
                    }
                    break;
                case KEY_PRESS_UP:
                    if (getDirection() == up) {
                        if (getY() < 60) {
                            moveTo(getX(), getY() + 1);
                        }
                    } else {
                        setDirection(up);
                    }
                    break;
                case KEY_PRESS_DOWN:
                    if (getDirection() == down) {
                        if (getY() > 0) {
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

    // Additional methods to manage Iceman's state
    int getHealth() const { return hp; }
    void decreaseHealth(int amount) { hp -= amount; }
    int getSonarCharge() const { return sonar; }
    void increaseSonarCharge() { sonar++; }
    int getGold() const { return gold; }
    void increaseGold() { gold++; }

private:
    int hp;
    int sonar;
    int gold;
    StudentWorld* getWorld(); // Assuming getWorld is implemented somewhere in your project
};

// Protester base class
class Protester : public Actor {
public:
    Protester(int img_ID, int startX, int startY, Direction dir = left, double size = 1.0, unsigned int depth = 0)
        : Actor(img_ID, startX, startY, dir, size, depth) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        // Define behavior for Protester
    }
};

// Hardcore Protester class
class HardcoreProtester : public Protester {
public:
    HardcoreProtester(int startX, int startY)
        : Protester(IID_HARD_CORE_PROTESTER, startX, startY, left, 1, 0) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        // Define behavior for Hardcore Protester
    }
};

// Ice class
class Ice : public Actor {
public:
    Ice(int startX, int startY)
        : Actor(IID_ICE, startX, startY, right, 0.25, 3) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        // Ice doesn't do anything each tick
    }
};

// Gold Nugget class
class GoldNugget : public Actor {
public:
    GoldNugget(int startX, int startY, bool isPermanent)
        : Actor(IID_GOLD, startX, startY, right, 1, 2), m_isPermanent(isPermanent) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        // Define behavior for Gold Nugget
    }

private:
    bool m_isPermanent;
};

// Oil Barrel class
class OilBarrel : public Actor {
public:
    OilBarrel(int startX, int startY)
        : Actor(IID_OIL_BARREL, startX, startY, right, 1, 2) 
    {
        setVisible(true);
    }

    virtual void doSomething() override {
        // Define behavior for Oil Barrel
    }
};

#endif // ACTOR_H_
