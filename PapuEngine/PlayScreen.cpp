#include "PlayScreen.h"
#include "Game.h"
#include "MyScreens.h"
#include <iostream>
#include <random>
#include <ctime>

PlayScreen::PlayScreen(Window* window) :_window(window)
{
}


PlayScreen::~PlayScreen()
{
}

void PlayScreen::initGUI() {

}

void PlayScreen::initSystem() {
	textureEnemiesVector.clear();
	textureEnemiesVector.push_back("Textures/Bacteria_Red.png");
	textureEnemiesVector.push_back("Textures/Bacteria_Blue.png");
	textureEnemiesVector.push_back("Textures/Bacteria_Green.png");

	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void PlayScreen::destroy() {

}

void PlayScreen::onExit() {}

void PlayScreen::onEntry() {
	camera.init(_window->getScreenWidth(), _window->getScreenHeight());
	camera.setPosition(
		glm::vec2(
			_window->getScreenWidth() / 2.0f,
			_window->getScreenHeight() / 2.0f)
	);
	initSystem();
	initGUI();
	backGround = new Background("Textures/game.png");
	ship = new Ship(6, "Textures/Doctor.png", &_inputManager);

	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randType(0, textureEnemiesVector.size()-1);
	typeOfEnemy = randType(randomEngine);
	//cout << typeOfEnemy << endl;
	enemy = new Enemy(6, textureEnemiesVector[typeOfEnemy],typeOfEnemy);

	_spriteBatch.init();

}



void PlayScreen::update() {

	camera.update();
	ship->update();
	enemy->update();

	//	time++;
	if (currentTime < timetoCreate)
	{
		currentTime++;

	}
	else{
		std::mt19937 randNumb(time(nullptr));
		std::uniform_int_distribution<int>randType(0, textureEnemiesVector.size()-1);
		typeOfEnemy = randType(randNumb);
		//cout << typeOfEnemy << endl;

		Enemy* newEnemy = new Enemy(6, textureEnemiesVector[typeOfEnemy],typeOfEnemy);
		enemiesVector.push_back(newEnemy);
		currentTime = 0;
	}


	for (size_t i = 0; i < enemiesVector.size(); i++)
	{
		enemiesVector[i]->update();
	}

	for each (Pill * pill in ship->pills_vector)
	{
		pill->update();
		if (pill->CollideWithBacteria(enemiesVector)) {
			std::cout << "Collisiono" << std::endl;
		}
	}

	//std::cout << time<<endl;
	checkInput();
}

void PlayScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		_game->onSDLEvent(event);
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(event.motion.x, event.motion.y);
			break;
		case  SDL_KEYUP:
			_inputManager.releaseKey(event.key.keysym.sym);
			break;
		case  SDL_KEYDOWN:
			_inputManager.pressKey(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(event.button.button);
			break;
		}
	}
}

void PlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint pLocation = _program.getUniformLocation("P");
	glm::mat4 cameraMatrix = camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();

	ship->draw(_spriteBatch);
	backGround->draw(_spriteBatch);
	enemy->draw(_spriteBatch);
	for (size_t i = 0; i < enemiesVector.size(); i++)
	{
		enemiesVector[i]->draw(_spriteBatch);
	}
	for each (Pill* pill in ship->pills_vector)
	{
		pill->draw(_spriteBatch);
	}

	_spriteBatch.end();
	_spriteBatch.renderBatch();
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();

}

void PlayScreen::drawHUD() {

}

void PlayScreen::build() {}

int PlayScreen::getPreviousScreen() const {
	return SCREEN_INDEX_MENU;
}

int PlayScreen::getNextScreen() const {
	return SCREEN_INDEX_OVER;
}
