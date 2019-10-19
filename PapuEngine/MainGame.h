#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include "Window.h"
#include "Camera2D.h"
#include <vector>
#include "SpriteBacth.h"
#include "Level.h"
#include "InputManager.h"
#include "Player.h"
#include "Human.h"
#include "PNGs.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	float _time;
	Window _window;
	void init();
	void procesInput();
	GLS_Program _program;
	vector<Sprite*> _sprites;
	vector<PNGs*> images;
	Camera2D _camera;
	SpriteBacth _spriteBacth;
	InputManager _inputManager;
	vector<Level*> levels;
	int currentLevel;
	void initLevel();
	Player* player;
	vector<Human*> humans;

public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};

