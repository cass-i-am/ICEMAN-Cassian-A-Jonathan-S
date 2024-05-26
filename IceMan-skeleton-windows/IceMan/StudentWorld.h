#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>

class Actor;
class Ice;



class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir) : GameWorld(assetDir) {};

	virtual int init();

	virtual int move();

	virtual void cleanUp();

private:
    IceBlock* ice[60][60];
    Player* iceMan;
    StudentWorld* gamePop;
};



#endif // STUDENTWORLD_H_

