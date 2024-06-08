#include "StudentWorld.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

template<typename T>
class list;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

int StudentWorld::init() {
	//populate student world

	for (int x = 0; x < 64; x++) {
		for (int y = 0; y < 64; y++) {
			if (x > 29 && x < 34 && y > 7) {
				ice[x][y] = new Ice(x,y,this);
				ice[x][y]->setVisible(false);
			}
			else if (y > 59) {
				ice[x][y] = new Ice(x, y, this);
				ice[x][y]->setVisible(false);
			}
			else {
				ice[x][y] = new Ice(x,y,this);
			}
		}
	}

	iceman = new Iceman{30, 60, this };
	actors.push_back(iceman);

	generateObjects();

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
	return GWSTATUS_PLAYER_DIED;
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
			delete ice[r][c];
			ice[r][c] = nullptr;
		}
	}

	// Delete Iceman
	delete iceman;
	iceman = nullptr;
}

void StudentWorld::generateObjects()
{
	srand(time(NULL));

	int temp = getLevel();
	num_boulder = min(temp / 2 + 2, 9);
	num_goldNug = max(5 - temp / 2, 2);
	num_barrels = min(2 + temp, 21);

	int b = num_boulder, g = num_goldNug, o = num_barrels;
	int numObj = b + g + o;


	Actor* world[64][64];
	for (int w1 = 0; w1 < 60; w1++) {
		for (int w2 = 0; w2 < 60; w2++) {
			world[w1][w2] = nullptr;
		}
	}
		
	for (int genPop = numObj; genPop > 0;) {

		if (b > 0) {
			GENB:
				int tempX = rand() % 56 + 4;
				if (tempX < 36 && tempX > 27) {
					goto GENB;
				}
				int tempY = rand()% 29 + 24;
				if (world[tempX][tempY] == nullptr) {
					world[tempX][tempY] = new Boulder(tempX, tempY, true, this);
					b--;
					genPop--;
					for (int xI = tempX; xI < tempX + 4; xI++) {
						for (int yI = tempY; yI < tempY + 4; yI++) {
							if (ice[xI][yI]->isVisible()) {
								ice[xI][yI]->setVisible(false);
							}
						}
					}
				}
				else {
					goto GENB;
				}
			}
	
		if (g > 0) {
			GENG:
				int tempX = rand() % 52 + 4;
				if (tempX < 36 && tempX > 27) {
					goto GENG;
				}
				int tempY = rand() % 49 + 4;
				if (world[tempX][tempY] == nullptr) {
					world[tempX][tempY] = new GoldNugget(tempX, tempY, true, this);
					g--;
					genPop--;
				}
				else {
					goto GENG;
				}
		}
		if (o > 0) {
			GENO:
				int tempX = rand() % 52 + 4;
				if (tempX < 36 && tempX > 27) {
					goto GENO;
				}
				int tempY = rand() % 49 + 4;
				if (world[tempX][tempY] == nullptr) {
					world[tempX][tempY] = new OilBarrel(tempX, tempY, this);
					o--;
					genPop--;
				}
				else {
					goto GENO;
				}
		}
	}

	for (int w1 = 0; w1 < 60; w1++) {
		for (int w2 = 0; w2 < 60; w2++) {
			if (world[w1][w2] != nullptr) {
				actors.push_back(world[w1][w2]);
			}
		}
	}

	for (int w1 = 0; w1 < 60; w1++) {
		for (int w2 = 0; w2 < 60; w2++) {
			world[w1][w2] = nullptr;
		}
	}

}

void StudentWorld::updateDisplayText() {
	int level = getLevel();
	int lives = getLives();
	int score = getScore();
	int gold = num_goldNug;
	int barrelsLeft = num_barrels;
	int health = iceman->getPatience();
	int squirts = iceman->getSquirt();
	int sonar = iceman->getSonar();

	string s = statLineFormat(level, lives, score, 
		gold, barrelsLeft, health, squirts, sonar);

	setGameStatText(s);

}

void StudentWorld::removeDeadGameObjects() {
	auto it = actors.begin();
	while (it != actors.end()) {
		if (!(*it)->isAlive()) {
			delete* it;
			it = actors.erase(it);
		}
		else {
			++it;
		}
	}
}

bool StudentWorld::thePlayerDiedDuringThisTick() {
	return !iceman->isAlive();
}

bool StudentWorld::thePlayerCompletedTheCurrentLevel() {
	for (auto actor : actors) {

	}
	return false; // Replace with actual condition
}

void StudentWorld::tellThisActorToDoSomething(Actor* actor) {
	actor->doSomething();
}

std::string StudentWorld::statLineFormat(int level, int lives,
	int score, int gold, int barrelsLeft,
	int health, int squirts, int sonar)
{
	std::string line = "Lvl: ";
	if (level < 10) {
		line += " " + std::to_string(level);
	}
	else {
		line += " " + std::to_string(level);
	}

	line += " Lives: " + std::to_string(lives);

	line += " Hlth: ";
	if (health == 10) {
		line += std::to_string(health) + "0%";
	}
	else {

		line += " " + std::to_string(health) + "0%";
	}

	line += " Wtr: ";
	if (squirts < 10) {
		line += std::to_string(squirts);
	}
	else {
		line += " " + std::to_string(squirts);
	}

	line += " Gld: ";
	if (gold < 10) {
		line += std::to_string(gold);
	}
	else {
		line += " " + std::to_string(gold);
	}

	line += " Oil Left: ";
	if (squirts < 10) {
		line += std::to_string(barrelsLeft);
	}
	else {
		line += " " + std::to_string(barrelsLeft);
	}

	line += " Sonar: ";
	if (sonar < 10) {
		line += std::to_string(sonar);
	}
	else {
		line += " " + std::to_string(sonar);
	}

	line += " Scr: ";
	if (score > 999999) {
		line += " 999999";
	}
	else if (score <= 999999 && score > 99999) {
		line += std::to_string(score);
	}
	else if (score <= 99999 && score > 9999) {
		line += "0" + std::to_string(score);
	}
	else if (score <= 9999 && score > 999) {
		line += "00" + std::to_string(score);
	}
	else if (score <= 999 && score > 99) {
		line += "000" + std::to_string(score);
	}
	else if (score <= 99 && score > 9) {
		line += "0000" + std::to_string(score);
	}
	else {
		line += "00000" + std::to_string(score);
	}

	return line;
}


void StudentWorld::destroyIce(int x, int y) {
	if (ice[x][y] != nullptr && ice[x][y]->isVisible()) {
		playSound(SOUND_DIG);
		ice[x][y]->setVisible(false);
	}
}