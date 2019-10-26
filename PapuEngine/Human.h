#pragma once
#include "Agent.h"

class Human : public Agent
{

protected:
	glm::vec2 _direction;
	bool ZombieState;
public:
	Human();
	~Human();
	void init(float speed, glm::vec2 position);

	void update(const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies);
	void changeColor(Color newColor);
	void changeZombieState(bool newState) { ZombieState = newState; }
	bool getZombieState() { return ZombieState; }
};

