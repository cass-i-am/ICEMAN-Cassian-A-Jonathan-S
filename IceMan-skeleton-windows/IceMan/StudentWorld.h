
// init() Details

// 	Your StudentWorlds init() method must:
// 		A. Initialize the data structures used to keep track of your games virtual GameWorld

// 		B. Constructs a new oil field that meets the requirements stated in the section below
// 		(filled with Ice, Barrels of oil, Boulders, Gold Nuggets, etc)
// 		C. Allocate and insert a valid Iceman object into the game world at the proper location.

// 		Your init() method must construct a representation of your virtual world and store this 
// 		in your student world object. It is required that you keep track of all the game objects 
// 		actors, like regular protesters, Gold nuggets, Barrels of oil, Sonar Kits, Boulders with 
// 		the exceptin of the ICE objects and the iceman object in a single STL collectin like a
// 		list of vector. To do so, wwe recommend using a vector of pointers to your game objects,
// 		or a list of pointers to your to your game objects. 

// 		If you like, You can store the pointer to the iceman seperately from all the other game 
// 		objects.

// 		Similarly, you may store store the pointers to all Ice objects in a different data 
// 		structure than the list/vector used for your other game actors. 

// 		HINT: Keep all the ice objects in a seperate 2D array of ice will speed things up. 

// 		Finally dont ever call the init funtion you just have to define it. Its already being
// 		called somwhere else in the heiarchy of the game and all the interlinked files etc. 

#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "vector.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir) : GameWorld(assetDir){}

	virtual int init()
	{	
		vector::vector<*actor>
		return GWSTATUS_CONTINUE_GAME;
	}

	virtual int move()
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
		decLives();



		// Put the actual function definition here......
		{
			//update the game status Line
			updateDisplayText(){
				 // update the score/lives text at screen top
			}; 

			// The term "Actors" refers to all Protestors, the player, Goodies, 
			// Boulders, Barrels of oil, Holes, Squirts, Exit, etc.
			//  Give each of the actors in the game world
			if (actor[i] is still active/alive)
			{
				// ask each actor to do something (e.g. move)
				tellThisActorToDoSomething(actor[i]);
				if(thePlayerDIedDuringThisTick()== True)
					return GWSTATUS_FINISHED_LEVEL;
			}

			//Remove newly-dead actors after each tick
			removeDeadGameObjects(); //delete dead game objects
			// return the proper result 
			if (thePLayerCompletedTheCurrentLevel() == True)
			{
				playFinishedLevelSoud();
				return GWSTATUS_FINISHED_LEVEL;
			}
			// the player hasnt completed the current level and hasnt died
			// let them continue playing the current level
			return GWSTATUS_CONTINUE_GAME;
		}

	}

	virtual void cleanUp(){
		// put code here..... 
	}

private:

Iceman* iceman;

Ice* IceField[64][64];

};




#endif // STUDENTWORLD_H_
