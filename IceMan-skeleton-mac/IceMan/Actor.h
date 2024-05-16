#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject {
private:

public:
    Actor(int imgid,int xpos, int ypos, Direction staDirection, StudentWorld* world, float size = 1.0, unsigned int dept=0 ) alive(true),
    GraphObject(imageID, startX, startY, startDirection, size, depth), 
    {
        setVisible(true);
    }
};


#endif // ACTOR_H_
