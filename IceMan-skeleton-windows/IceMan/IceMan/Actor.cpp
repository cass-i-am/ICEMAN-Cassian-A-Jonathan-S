#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject{
public:

    Actor::Actor(int imageID, int startx, int starty, Direction dir, StudentWorld* world, double size, unsigned int depth): GraohObject(imageID, startX, startY, dir, size, depth){
        setVisibility(true);
    }

}; 



