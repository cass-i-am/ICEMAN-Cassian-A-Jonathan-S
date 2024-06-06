#include "Actor.h"
#include "StudentWorld.h"

Actor::Actor(int imageID, int startX, int startY, Direction dir, StudentWorld* world, double size, unsigned int depth)
    : GraphObject(imageID, startX, startY, dir, size, depth), alive(true), m_world(world) {
    setVisible(true);
}

Iceman::Iceman(int startX, int startY, StudentWorld* world)
    : Actor(IID_PLAYER, startX, startY, right, world, 1.0, 0) {
    setVisible(true);
}

void Iceman::doSomething() {
    int ch;
    if (getWorld()->getKey(ch)) {
        switch (ch) {
            case KEY_PRESS_LEFT:
                if (getDirection() == left && getX() > 0) moveTo(getX() - 1, getY());
                else setDirection(left);
                break;
            case KEY_PRESS_RIGHT:
                if (getDirection() == right && getX() < 60) moveTo(getX() + 1, getY());
                else setDirection(right);
                break;
            case KEY_PRESS_UP:
                if (getDirection() == up && getY() < 60) moveTo(getX(), getY() + 1);
                else setDirection(up);
                break;
            case KEY_PRESS_DOWN:
                if (getDirection() == down && getY() > 0) moveTo(getX(), getY() - 1);
                else setDirection(down);
                break;
            case KEY_PRESS_SPACE:
                // Implement shooting behavior
                break;
            case KEY_PRESS_ESCAPE:
                // Implement quitting behavior
                break;
        }
    }
}

Protester::Protester(int imageID, int startX, int startY, StudentWorld* world, Direction dir, double size, unsigned int depth)
    : Actor(imageID, startX, startY, dir, world, size, depth) {
    setVisible(true);
}

HardcoreProtester::HardcoreProtester(int startX, int startY, StudentWorld* world)
    : Protester(IID_HARD_CORE_PROTESTER, startX, startY, world) {
    setVisible(true);
}

void HardcoreProtester::doSomething() {
    // Implement hardcore protester behavior
}

Ice::Ice(int startX, int startY, StudentWorld* world)
    : Actor(IID_ICE, startX, startY, right, world, 0.25, 3) {
    setVisible(true);
}

void Ice::doSomething() {
    // Implement Ice behavior
}

GoldNugget::GoldNugget(int startX, int startY, bool isPermanent, StudentWorld* world)
    : Actor(IID_GOLD, startX, startY, right, world, 1.0, 2), m_isPermanent(isPermanent) {
    setVisible(true);
}

void GoldNugget::doSomething() {
    // Implement GoldNugget behavior
}

OilBarrel::OilBarrel(int startX, int startY, StudentWorld* world)
    : Actor(IID_BARREL, startX, startY, right, world, 1.0, 2) {
    setVisible(true);
}

void OilBarrel::doSomething() {
    // Implement OilBarrel behavior
}
