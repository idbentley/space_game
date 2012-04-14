#ifndef SPRITELIB_H
#define SPRITELIB_H

#include <iostream>
#include "SDL.h"
#include <map>
#include "Engine.h"
using namespace std;

class SpriteLib{
	private:
		static SpriteLib *instance;
		map<string, SDL_Surface *> sprites;
		SpriteLib();
		~SpriteLib();
		SDL_Surface *getSpriteMap(string file);
	public:
		static SpriteLib *getInstance();
		void renderSprite(int x, int y, int spritex, int spritey, int numMods, int numSprites, SDL_Surface *sprite);
		SDL_Surface *getSprite(string file);
		void drawBG(string file);
};

#endif
