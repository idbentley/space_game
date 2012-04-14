#include "EventHandler.h"
EventHandler::EventHandler(){}
EventHandler *EventHandler::instance = NULL;
EventHandler *EventHandler::getInstance(){
		if(instance == NULL)
				return new EventHandler();
		return instance;
}
void EventHandler::processEvents(){
	//Events get Handled here.
	Engine *engine = Engine::getInstance();
	Ship *ship = engine->getShip();
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_UP:
						ship->thrust(0);
						break;
					case SDLK_DOWN:
						ship->thrust(1);
						break;
					case SDLK_LEFT:
						ship->rotating(0);
						break;
					case SDLK_RIGHT:
						ship->rotating(1);
						break;
					case SDLK_ESCAPE:
						//TODO start menu!
						break;	
					default:
						break;
				}
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym){
					case SDLK_UP:
						ship->stopThrusting(0);
						break;
					case SDLK_DOWN:
						ship->stopThrusting(1);
						break;
					case SDLK_LEFT:
						ship->stopRotating(0);
						break;
					case SDLK_RIGHT:
						ship->stopRotating(1);
						break;
					default:
						break;
				}
				break;
			case SDL_QUIT:
				exit(0);
				break;
			default:
				break;
		}
	}
}

void EventHandler::processMenuEvents(Menu* menu){
	
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_UP:
						menu->decSelected();
						break;
					case SDLK_DOWN:
						menu->incSelected();
						break;
					case SDLK_RETURN:
						menu->execCommand();
						break;
					default:
						break;
				}

				break;
			case SDL_QUIT:
				exit(0);
				break;
			default:
				break;
		}
	}
}
