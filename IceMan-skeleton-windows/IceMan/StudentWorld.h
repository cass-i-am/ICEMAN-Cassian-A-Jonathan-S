#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>

struct Spawn { int x; int y; };

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir) : GameWorld(assetDir) {};

	virtual int init() override;

	virtual int move() override;

	virtual void cleanUp() override;

	void destroyIce(int x, int y);

private:
    Ice* ice[64][64];
    Iceman* iceman;
	std::vector<Actor*>actors;
	int num_barrels;
	int num_goldNug;
	int num_boulder;

	
	void generateObjects();
	void updateDisplayText();
	void removeDeadGameObjects();
	bool thePlayerDiedDuringThisTick();
	bool thePlayerCompletedTheCurrentLevel();
	void tellThisActorToDoSomething(Actor* actor);
	std::string statLineFormat(int level, int lives, 
		int score, int gold, int barrelsLeft, 
		int health, int squirts, int sonar);

};



#endif // STUDENTWORLD_H_

