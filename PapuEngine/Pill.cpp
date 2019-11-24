#include "Pill.h"
#include "ResourceManager.h"
#include <SDL\SDL.h>

Pill::Pill(std::string texture, int type, glm::vec2 position)
{
	this->texture = texture;
	currentType = type;
	this->position = position;
	textureID = ResourceManager::getTexture(this->texture).id;
	speed = 2;
}

void Pill::draw(SpriteBacth& spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 20, 25);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Pill::update()
{
	position.y += speed;
}

bool Pill::CollideWithBacteria(std::vector<Enemy *> enemy_vector)
{
	PrintPosition(position,"pill");
	for each (Enemy* enemy in enemy_vector)
	{
		PrintPosition(enemy->getPosition(),"bacteria");
		const float MIN_DISTANCE = pill_radius * 2.0f;

		glm::vec2 centerPosA = position + glm::vec2(pill_radius);

		glm::vec2 centerPosB =
			enemy->getPosition() + glm::vec2(pill_radius);

		glm::vec2 distVec = centerPosA - centerPosB;
		float distance = glm::length(distVec);

		float collisionDepth = MIN_DISTANCE - distance;
		if (collisionDepth > 0) {
			glm::vec2 collisionDepthVec =
				glm::normalize(distVec) * collisionDepth;

			position += collisionDepth / 2.0f;
			enemy->getPosition() -= collisionDepth / 2.0f;
			return true;
		}
	}
	return false;
}

#include <iostream>
void Pill::PrintPosition(glm::vec2 _position, std::string name) {
	std::cout <<name<<" "<< _position.x << "," << _position.y << "\n";
}

Pill::~Pill()
{
}
