#include "StudentWorld.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init(){

	// p1 =

	int rows = 64;
	int cols = 64; 
	
	for(int rws = 0; rws < rows ; rws++){
		for(int clms = 0; clms < cols; clms++){
			IceField[rws][clms] = new Ice(rws, clms, this);
		}

		if (rws >= 30 && rws <= 33){
			for(int clms = 30; clms <= 33; clms++){
				IceField[rws][clms] = nullptr;
			}
		}
	}



	return GWSTATUS_CONTINUE_GAME;
}