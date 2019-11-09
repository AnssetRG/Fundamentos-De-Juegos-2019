#pragma once
#include "Agent.h"
#include "InputManager.h"

class Player: public Agent
{
private:
	InputManager* inputManager;
public:
	Player(float agent_width, float agent_height, glm::vec2 position,std::string texture, InputManager* _inputManager);
	void update();
	void setPosition(glm::vec2 position) {_position = position;}
	void changeTexture(std::string texturePath) {_texturePath = texturePath;}
	~Player();
};

