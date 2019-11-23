#include "Ship.h"
#include "ResourceManager.h"
#include <SDL\SDL.h>

Ship::Ship(float _speed, std::string texture, InputManager* _inputManager)
{
	speed = _speed;
	position = glm::vec2(350, 100);
	textureID = ResourceManager::getTexture(texture).id;
	inputManager = _inputManager;
	texturesVector.push_back("Textures/p1.png");
	texturesVector.push_back("Textures/p2.png");
	texturesVector.push_back("Textures/p3.png");
	texturesVector.push_back("Textures/p4.png");

}

void Ship::draw(SpriteBacth & spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 50, 50);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Ship::setColor(ColorRGBA color)
{
}

void Ship::update()
{

	if (inputManager->isKeyPressed(SDLK_w)) {
		if (position.y < screendHeightLimits) {
			position.y += speed;
		}
	}
	if (inputManager->isKeyPressed(SDLK_s)) {
		if (position.y > 0) {
			position.y -= speed;
		}
	}
	if (inputManager->isKeyPressed(SDLK_a)) {
		if (position.x > 0) {
			position.x -= speed;
		}
	}
	if (inputManager->isKeyPressed(SDLK_d)) {
		if (position.x < screenWidthLimits) {
		position.x += speed;
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

}

void Ship::ChangeShipType(std::string texture)
{
	textureID = ResourceManager::getTexture(texture).id;
}

Ship::~Ship()
{

}

