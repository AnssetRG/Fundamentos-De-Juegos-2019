#pragma once
#include <glm\glm.hpp>
#include "SpriteBacth.h"
#include "GLTexture.h"
#include <string>
using namespace std;

const int PNG_WIDTH = 60;

class PNGs
{
private:
	glm::vec2 position;
	float speed;
	Color color;
	string imgURL;
public:
	PNGs();
	~PNGs();
	void init(glm::vec2 _position, string _imgURL);
	void draw(SpriteBacth& spritebatch);
};

