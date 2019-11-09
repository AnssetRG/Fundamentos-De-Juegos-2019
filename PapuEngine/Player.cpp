#include "Player.h"
#include <SDL\SDL.h>


Player::Player(float agent_width, float agent_height, glm::vec2 position, std::string texture, InputManager* _inputManager) : 
	Agent(agent_width,agent_height, position, texture)
{
	inputManager = _inputManager;
}

void Player::update()
{
	if (inputManager->isKeyDown(SDLK_w)) {
		_position.y += 6.0f;
		if (_position.y > 420) _position.y = 420;
	}
	if (inputManager->isKeyDown(SDLK_s)) {
		_position.y -= 6.0f;
		if (_position.y <= 0) _position.y = 0;
	}
	if (inputManager->isKeyDown(SDLK_a)) {
		_position.x -= 6.0f;
		if (_position.x <= -100) _position.x = 710;
	}
	if (inputManager->isKeyDown(SDLK_d)) {
		_position.x += 6.0f;
		if (_position.x >= 730) _position.x = -110;
	}
}

Player::~Player()
{
}
