#pragma once
#include "Agent.h"
class Enemy : public Agent
{
	Enemy(float agent_width,float agent_height,glm::vec2 position,std::string texture);
	void update() { _position.y -= 4.0f; }
	void setPosition(glm::vec2 position) {_position = position;}
	void changeTexture(std::string texturePath) {_texturePath = texturePath;}
	~Enemy();
};

