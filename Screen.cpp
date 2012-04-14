#include "Screen.h"

Screen::Screen(Config *config){
		this->config = config;
}

int Screen::init(){
	//We must first initialize the SDL video component, and check for success
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Unable to initialize SDL Video: " << SDL_GetError() << endl;
		return 1;
	}
								
	//When this program exits, SDL_Quit must be called
							
	//Set the video mode to fullscreen and double-buffering
	int screen_x = DEFAULT_X;
	int screen_y = DEFAULT_Y;
	int screen_color = DEFAULT_COLOR;
	if(config->getConfigValue("screen_x")!=""){screen_x = Util::strtoint(config->getConfigValue("screen_x"));}	
	if(config->getConfigValue("screen_y")!=""){screen_y = Util::strtoint(config->getConfigValue("screen_y"));}
	if(config->getConfigValue("screen_color")!=""){screen_color = Util::strtoint(config->getConfigValue("screen_color"));}
	
	screen = SDL_SetVideoMode(screen_x,screen_y,screen_color, SDL_DOUBLEBUF);
	if (screen == NULL) {
		cout << "Unable to set video mode: " << SDL_GetError() << endl;
		return 1;
	}
	atexit(SDL_Quit);
	return 0;
}

void Screen::setScreenSurface(SDL_Surface* newScreenSurface){
	screen = newScreenSurface;
}

SDL_Surface* Screen::getScreenSurface(){
	return screen;
}
void Screen::clearScreen(){
	SDL_FillRect(screen, NULL, 0);
}
