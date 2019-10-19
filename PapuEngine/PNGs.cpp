#include "PNGs.h"
#include "ResourceManager.h"

PNGs::PNGs()
{
}

PNGs::~PNGs()
{
}

void PNGs::init(glm::vec2 _position, string _imgURL)
{
	position = _position;
	color.r = 240;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	imgURL = _imgURL;
}

void PNGs::draw(SpriteBacth& spritebatch) {
	int textureID = ResourceManager::getTexture(imgURL).id;
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	glm::vec4 destRect(position.x, position.y, PNG_WIDTH, PNG_WIDTH);
	spritebatch.draw(destRect, uvRect, textureID, 0.0f, color);
}
