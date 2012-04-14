#ifndef ENGINE_H
#define ENGINE_H

//State definitions
#define STOPPED		0
#define MENU		1
#define GAME		2
#define GAME_MENU	3

#include <iostream>
#include <vector>
#include "Screen.h"
#include "Ship.h"
#include "Physics.h"
#include "Render.h"
#include "Menu.h"
#include "EventHandler.h"
#include "SpriteLib.h"
#include "Config.h"

class Render;
class EventHandler;
class SpriteLib;
using namespace std;
class Engine{
	private:
		Engine();
		~Engine();
		static Engine *instance;
		static int gameState;
		//static vector *collection;
		//static state monitor variable
		Screen* mainScreen;
		Physics* physicsEngine;
		Render* renderEngine;
		Config* config;
		vector<Object *> objs;
		Menu *curMenu;
		EventHandler *eH;
		Ship *ship;
		SpriteLib *spriteLib;
	public:
		static Engine* getInstance();
		//
		//gets the screen member of the engine
		//
		Screen* getScreen();
		//
		//sets the screen member of the engine
		//
		void setScreen(Screen* newScreen);
		
		void setShip(Ship *ship);

		Ship *getShip();
		//
		//Starts the engine, inits screen
		//
		void initGame(Config *config);
		//
		//Starts the engine, inits screen
		//
		void startEngine();
		//
		//Destroys screen and event handlers
		//
		void stopEngine();
		//
		//Main game loop goes here (for now)
		//
		void gameLoop();
		//
		//Run loop associated with menu
		//
		void menu();
		//
		//Run loop associated with playing
		//
		void playing();
		//
		//Run loop associated with inGameMenu
		//
		void inGameMenu();
		//
		//Perform action by moving to state specified in gameState variable
		//
		void executeState();
		void setCurMenu(Menu *);
		void setGameState(int );
};

#endif
