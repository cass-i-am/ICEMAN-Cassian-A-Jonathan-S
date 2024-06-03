#include "StudentWorld.h"
#include <string>
#include <vector>
using namespace std;

template<typename T>
class list;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

int StudentWorld::init() {
	//populate student world

	for (int x = 0; x < 60; x++) {
		for (int y = 0; y < 60; y++) {
			if (x < 28 || x > 32) {
				ice[x][y] = new IceBlock{ IID_ICE, x, y };
				ice[x][y]->setVisible(true);
			}
			else {
				ice[x][y] = nullptr;
			}
		}
	}

	iceMan = new Player{ IID_PLAYER, 30, 60 };
	iceMan->setVisible(true);




	/*
	
	
	generate ice rows 0-59 (except columns 30-33)

	place ice man at [30][60]
		if game start
		if iceman lost life

	distribute at random:
		Boulders: int B = min(current_level_number / 2+2,9)

		Gold Nuggets: int G = max(5 - current_level_number / 2,2)

		Barrels of Oil: int L = min(2 + current_level_number, 21)

	extra conditionals:
		Euclidian distance (6 squares)
		Spawned gold nuggets permanent until Iceman contact
		Gold + Oil Barrels start in invisible state
		Sonar
		clear out 4x4 of ice over boulders

	*/
	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
	// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
	// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	decLives();
	return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::cleanUp() {
	for (int x = 0; x < 60; x++) {
		for (int y = 0; y < 60; y++) {
			if (x < 28 || x > 32) {
				delete ice[x][y];
				ice[x][y] = nullptr;
			}
		}
	}
}

