#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"
#include "Enemy.h"
#include <list>
class Pill
{
private:
	float speed;
	std::string texture;
	int textureID;
	glm::vec2 position;
	int screenWidthLimits = 710;
	int screendHeightLimits = 450;
	int currentType = 0;
	void PrintPosition(glm::vec2 _position, std::string name);

public:
	Pill(std::string texture, int type, glm::vec2 position);
	float pill_radius;
	void draw(SpriteBacth& spriteBatch);
	void update();
	Enemy* CollideWithBacteria(std::list<Enemy*> enemy_list);
	~Pill();
};

