#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"

class Enemy
{
private:
	float speed;
	std::string texture;
	int textureID;
	glm::vec2 position;
	int enemyType = -1;

public:
	Enemy(float _speed, std::string texture, int _enemyType);
	float enemy_radius;
	void draw(SpriteBacth& spriteBatch);
	void setColor(ColorRGBA color);
	glm::vec2 getPosition()const {
		return position;
	}
	int getEnemyType() { return enemyType; }
	void update();
	~Enemy();

};

