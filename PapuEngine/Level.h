#pragma once
#include <string>
#include <vector>
#include "SpriteBacth.h"
#include <stdlib.h> 
#include <time.h>

using namespace std;

const int TILE_WIDTH = 64;

class Level
{
private:
	vector<string> levelData;
	int numHumans;
	void parseLevel();
public:
	Level(const string& filename);
	glm::vec2 playerPosition;
	vector<glm::vec2> zombiesPosition;
	vector<glm::vec2> freePosition;
	glm::vec2 getPlayerPosition() const {
		return playerPosition;
	}
	vector<glm::vec2> getZombiesPosition()const {
		return zombiesPosition;
	}
	glm::vec2 getRandomPosition();
	void draw();
	SpriteBacth spritebatch;
	~Level();
};

