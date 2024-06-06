#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <vector>
#include <string>

class StudentWorld : public GameWorld {
public:
    StudentWorld(std::string assetDir) : GameWorld(assetDir), iceman(nullptr) {}

    virtual int init() override;
    virtual int move() override;
    virtual void cleanUp() override;
    void destroyIce(int x, int y);

private:
    Iceman* iceman;
    Ice* iceField[64][64];
    std::vector<Actor*> actors;

    void updateDisplayText();
    void removeDeadGameObjects();
    bool thePlayerDiedDuringThisTick();
    bool thePlayerCompletedTheCurrentLevel();
    void tellThisActorToDoSomething(Actor* actor);
};





#endif // STUDENTWORLD_H_
