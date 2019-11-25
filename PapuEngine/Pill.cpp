#include "Pill.h"
#include "ResourceManager.h"
#include <SDL\SDL.h>
#include <iostream>

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

Enemy* Pill::CollideWithBacteria(std::list<Enemy*> enemy_list)
{
	for each (Enemy* enemy in enemy_list)
	{
		glm::vec4 enemigo_data(enemy->getPosition(), enemy->getPosition().x +50, enemy->getPosition().y +50);
		glm::vec4 pill_data(this->position, this->position.x+20, this->position.y+25);

		if (enemigo_data.x < pill_data.z &&
			pill_data.x < enemigo_data.z &&
			enemigo_data.y < pill_data.w &&
			pill_data.y < enemigo_data.w && currentType == enemy->getEnemyType()) {
			return enemy;
		}
	}
	return NULL;
}


Pill::~Pill()
{
}
