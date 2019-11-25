#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"
#include "Pill.h"
#include <list>

class Ship
{

private:
	float speedX;
	float speedY;
	std::string texture;
	int textureID;
	glm::vec2 position;
	InputManager* inputManager;
	int screenWidthLimits = 710;
	int screendHeightLimits = 450;
	std::vector<std::string> texturesVector;
	bool Fire_pressed = false;
	
	int currentType = 0;

public:
	std::list<Pill*> pills_vector;
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

