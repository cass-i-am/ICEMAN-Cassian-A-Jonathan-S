#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir) {
    return new StudentWorld(assetDir);
}

int StudentWorld::init() {
    // Initialize Ice field
    for (int r = 0; r < 64 - 4; r++) {
        for (int c = 0; c < 64; c++) {
                iceField[r][c] = new Ice(r, c, this);
            }
        }
    

    for (int r = 0; r < 64 - 4; r++){
        for (int c = 0; c < 64; c++){
            if (r >= 30 && r < 34 && c > 3) {
                iceField[r][c]->setVisible(false);
            }
        }
    }





    // Initialize Iceman
    iceman = new Iceman(30, 60, this);
    actors.push_back(iceman);

    // Initialize other actors (e.g., Boulders, Gold Nuggets, Barrels of Oil)
    // ...

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
    // Update game status line
    updateDisplayText();

    // Give each actor a chance to do something
    for (auto actor : actors) {
        if (actor->isAlive()) {
            actor->doSomething();
            if (thePlayerDiedDuringThisTick()) {
                decLives();
                return GWSTATUS_PLAYER_DIED;
            }
        }
    }

    // Remove dead actors
    removeDeadGameObjects();

    // Check if the player completed the current level
    if (thePlayerCompletedTheCurrentLevel()) {
        playSound(SOUND_FINISHED_LEVEL);
        return GWSTATUS_FINISHED_LEVEL;
    }

    // The player hasn't completed the current level and hasn't died
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp() {
    // Delete all actors
    for (auto actor : actors) {
        delete actor;
    }
    actors.clear();

    // Delete Ice field
    for (int r = 0; r < 64; r++) {
        for (int c = 0; c < 64; c++) {
            delete iceField[r][c];
            iceField[r][c] = nullptr;
        }
    }

    // Delete Iceman
    delete iceman;
    iceman = nullptr;
}

void StudentWorld::updateDisplayText() {
    // Update the score/lives text at the screen top
}

void StudentWorld::removeDeadGameObjects() {
    auto it = actors.begin();
    while (it != actors.end()) {
        if (!(*it)->isAlive()) {
            delete *it;
            it = actors.erase(it);
        } else {
            ++it;
        }
    }
}

bool StudentWorld::thePlayerDiedDuringThisTick() {
    return !iceman->isAlive();
}

bool StudentWorld::thePlayerCompletedTheCurrentLevel() {
    // Check if the player completed the level
    // This could be based on specific game conditions
    return false; // Replace with actual condition
}

void StudentWorld::tellThisActorToDoSomething(Actor* actor) {
    actor->doSomething();
}


void StudentWorld::destroyIce(int x, int y){
    if(iceField[x][y] !=nullptr && iceField[x][y]->isVisible()){
        playSound(SOUND_DIG);
        iceField[x][y]->setVisible(false); 
    }
}