#include "PlayScreen.h"
#include "Game.h"
#include "MyScreens.h"



PlayScreen::PlayScreen(Window* window):_window(window)
{
}


PlayScreen::~PlayScreen()
{
}

void PlayScreen::initGUI() {
	
}

void PlayScreen::initSystem() {
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
	background  = new Background("Textures/game2.png");
	_spriteBatch.init();

	player = new Player(53, 39, glm::vec2((_window->getScreenHeight() / 2) + 50, 20), "Textures/Player.png", &_game->_inputManager);
	enemies.push_back(new Enemy(60, 60, glm::vec2(_window->getScreenWidth() - 80, _window->getScreenHeight() * 0.75), "Textures/piedra.png"));
	enemies.push_back(new Enemy(60, 60, glm::vec2(_window->getScreenWidth() - 40, _window->getScreenHeight() * 0.75), "Textures/piedra.png"));
	enemies.push_back(new Enemy(60, 60, glm::vec2(_window->getScreenWidth(), _window->getScreenHeight() * 0.75), "Textures/piedra.png"));
}



void PlayScreen::update() {
	camera.update();
	checkInput();
	player->update();
	for each (Enemy * enemy in enemies)
	{
		enemy->update;
	}
}

void PlayScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		_game->onSDLEvent(event);
	}
}

void PlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint pLocation = _program.getUniformLocation("P");
	glm::mat4 cameraMatrix = camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();
	background->draw(_spriteBatch);
	player->draw(_spriteBatch);
	for each (Enemy* enemy in enemies)
	{
		enemy->draw(_spriteBatch);
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
