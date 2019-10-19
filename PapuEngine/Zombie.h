#pragma once
#include "Agent.h"
class Zombie:public Agent
{
public:
	Zombie();
	~Zombie();
	void init(glm::vec2 _position, string _imgURL);
	void update();
};

