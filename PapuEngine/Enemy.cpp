#include "Enemy.h"
#include "ResourceManager.h"
#include <random>
#include <ctime>
Enemy::Enemy(float _speed, std::string texture, int _enemyType)
{
	speed = _speed;
	enemyType = enemyType;
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPosY(1, 600);

	position = glm::vec2(randPosY(randomEngine), 500);
	textureID = ResourceManager::getTexture(texture).id;
	enemy_radius = 50 / 2;
}


void Enemy::draw(SpriteBacth& spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 50, 50);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Enemy::setColor(ColorRGBA color)
{
}

void Enemy::update()
{
	position.y -= speed;
}

Enemy::~Enemy()
{
}
