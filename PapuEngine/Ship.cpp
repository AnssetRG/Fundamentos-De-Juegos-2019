#include "Ship.h"
#include "ResourceManager.h"
#include <iostream>
#include <SDL\SDL.h>

Ship::Ship(float _speed, std::string texture, InputManager* _inputManager)
{
	speedX = _speed;
	speedY = _speed / 2;
	position = glm::vec2(350, 100);
	textureID = ResourceManager::getTexture(texture).id;
	inputManager = _inputManager;
	texturesVector.push_back("Textures/Pill_red.png");
	texturesVector.push_back("Textures/Pill_blue.png");
	texturesVector.push_back("Textures/Pill_green.png");

}

void Ship::draw(SpriteBacth & spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 40, 50);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Ship::setColor(ColorRGBA color)
{
}

void Ship::update()
{

	if (inputManager->isKeyPressed(SDLK_w)) {
		if (position.y < screendHeightLimits) {
			position.y += speedY;
		}
	}
	if (inputManager->isKeyPressed(SDLK_s)) {
		if (position.y > 0) {
			position.y -= speedY;
		}
	}
	if (inputManager->isKeyPressed(SDLK_a)) {
		if (position.x > 0) {
			position.x -= speedX;
		}
	}
	if (inputManager->isKeyPressed(SDLK_d)) {
		if (position.x < screenWidthLimits) {
		position.x += speedX;
		}
	}

	if (inputManager->isKeyReleased(SDLK_e) == true) {
		currentType = currentType + 1;
		if (currentType>=texturesVector.size()-1) {
			currentType = 0;
		}

		ChangeShipType(texturesVector[currentType]);
	}
	if (inputManager->isKeyPressed(SDLK_q)) {
		currentType = currentType - 1;
		if (currentType <= 0) {
			currentType = texturesVector.size() - 1;
		}
		ChangeShipType(texturesVector[currentType]);
	}
	if (!Fire_pressed && inputManager->isKeyDown(SDLK_SPACE) == true) {
		Fire();
		Fire_pressed = true;
	}else if (Fire_pressed && inputManager->isKeyDown(SDLK_SPACE) == false) Fire_pressed = false;
}

void Ship::ChangeShipType(std::string texture)
{
	textureID = ResourceManager::getTexture(texture).id;
}

void Ship::Fire()
{
	
	Pill* newPill = new Pill(texturesVector[currentType],currentType,position);
	pills_vector.push_back(newPill);
}

Ship::~Ship()
{

}

