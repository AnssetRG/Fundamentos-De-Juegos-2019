#include "Zombie.h"



Zombie::Zombie()
{
}


Zombie::~Zombie()
{
}

void Zombie::init(glm::vec2 _position, string _imgURL)
{
	position = _position;
	color.r = 240;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	imgURL = _imgURL;
}

void Zombie::update()
{
}
