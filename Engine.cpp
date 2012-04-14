#include "Engine.h"
#include "MainMenu.h"
#include "SDL_ttf.h"
#include "StatObj.h"

Engine *Engine::instance = NULL;
int Engine::gameState;

Engine::Engine(){
	gameState = STOPPED;
	eH = EventHandler::getInstance();	
}
Engine::~Engine(){}


Engine *Engine::getInstance(){
	if(instance == NULL)
		instance = new Engine();
	return instance;
}

Screen* Engine::getScreen(){
	return mainScreen;
}

void Engine::setScreen(Screen* newScreen){
	mainScreen = newScreen;
}

void Engine::setShip(Ship *s){
	ship = s;
}
Ship *Engine::getShip(){
	return ship;
}

void Engine::initGame(Config *config){
	//Init Screen
	this->config = config;

	mainScreen = new Screen(config);
	spriteLib = SpriteLib::getInstance();
	if(mainScreen->init() == 1){
			cout << "Could not initialize video.  Cannot continue." << endl;
			exit(0);
	}
	if(TTF_Init() == -1){
			cout << "Could not initialize TTF.  Cannot continue." << endl;
			exit(0);
	}
	curMenu = new MainMenu();
	ship = new Ship();
	objs.push_back(ship);
	//objs.push_back(new StatObj(Vec2(200.0f, 200.0f), Vec2(0.0f, -1.0f), Vec2(0.0f, -0.1f), 1, 1, 1, 1, 1, "sprites/ast.bmp", 32)); 
	//Set gamestate
	gameState = MENU;
	//Execute the change of state! Horaaayy
	executeState();

}

void Engine::startEngine(){

}

void Engine::stopEngine(){

}

void Engine::gameLoop(){

}

void Engine::setCurMenu(Menu *cM){
	curMenu = cM;
}

void Engine::menu(){
	while(SDL_QUIT){
		mainScreen->clearScreen();	
		eH->processMenuEvents(curMenu);
		curMenu->renderMenu();
		executeState();
	}

}

void Engine::playing(){
	mainScreen->clearScreen();
	spriteLib->drawBG("backdrops/bg1.bmp");
	eH->processEvents();
	physicsEngine->applyPhysics(objs);
	renderEngine->renderScene(objs);
	ship->go();
	usleep(10000);
	executeState();
}

void Engine::inGameMenu(){
	//TODO: This is important.
//	mainScreen->clearScreen();
	//eH->processMenuEvents();
//	renderEngine->renderScene(objs);
	//inGameMenu->renderMenuSelection();
}
void Engine::setGameState(int state){
	gameState = state;
}

void Engine::executeState(){
	switch(gameState){
		case MENU:
			menu();
			break;
		case GAME:
			playing();
			break;		
		case GAME_MENU:
			inGameMenu();
			break;
	}
}
