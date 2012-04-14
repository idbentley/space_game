#ifndef SCREEN_H
#define SCREEN_H

#define DEFAULT_X 640
#define DEFAULT_Y 480
#define DEFAULT_COLOR 32

#include <iostream>
#include "SDL.h"
#include "Config.h"
#include "Util.h"

using namespace std;

class Screen{
	private:
		SDL_Surface *screen;
		Config* config;
	public:
		Screen(Config *config);
		int init();
		SDL_Surface* getScreenSurface();
		void setScreenSurface(SDL_Surface* newScreenSurface);
		void clearScreen();
};
#endif
