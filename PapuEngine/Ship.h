#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"

class Ship
{

private:
	float speed;
	std::string texture;
	int textureID;
	glm::vec2 position;
	InputManager* inputManager;
	int screenWidthLimits = 710;
	int screendHeightLimits = 450;
	std::vector<std::string> texturesVector;
	int currentType = 0;

public:
	Ship(float _speed, std::string texture, InputManager* _inputManager);
	void draw(SpriteBacth& spriteBatch);
	void setColor(ColorRGBA color);
	glm::vec2 getPosition()const {
		return position;
	}
	void update();
	void ChangeShipType(std::string texture);
	void Fire();
	~Ship();

};

