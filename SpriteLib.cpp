#include "SpriteLib.h"
SpriteLib *SpriteLib::instance = NULL;

SpriteLib::SpriteLib(){}
SpriteLib::~SpriteLib(){}
SpriteLib *SpriteLib::getInstance(){
	if(instance == NULL)
		instance = new SpriteLib();
	return instance;
}
SDL_Surface *SpriteLib::getSpriteMap(string file){
	SDL_Surface *image;
	/* Load the BMP file into a surface */
	image = SDL_LoadBMP(file.c_str());
	if ( image == NULL ) {
		cout << "Couldn't load " << file << " " << SDL_GetError() << endl;
		exit(0);
    }
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 255, 0, 143));
	return image;
}
void SpriteLib::renderSprite(int x, int y, int spritex, int spritey, int numModes, int numSprites, SDL_Surface *sprite){
	Engine *engine = Engine::getInstance();
	int w = sprite->w/numSprites;
	int h = sprite->h/numModes;
	SDL_Rect src;
	SDL_Rect dest;
	src.x = w*spritex;
	src.y = h*spritey;
	src.w = w;
	src.h = h;
	dest.x = x-(static_cast<float>(w)/2.0f);
	dest.y = y-(static_cast<float>(h)/2.0f);
	SDL_BlitSurface(sprite, &src, engine->getScreen()->getScreenSurface(), &dest); 
//	SDL_UpdateRect(engine->getScreen()->getScreenSurface(), dest.x, dest.y, w, h);
}
SDL_Surface *SpriteLib::getSprite(string file){
	map<string, SDL_Surface *>::iterator sprite;
	sprite = SpriteLib::sprites.find(file);
	if(sprite == SpriteLib::sprites.end()){
		SDL_Surface *temp = getSpriteMap(file);
		SpriteLib::sprites[file] = temp;
		return temp;
	}else{
		//Weird notation.  Here * means the item that the iterator is pointing at.
		return (*sprite).second;
	}
}

void SpriteLib::drawBG(string file){
	Engine *engine = Engine::getInstance();
	SDL_Surface *image = getSprite(file.c_str());
	if ( image == NULL ) {
		cout << "Couldn't load " << file << " " << SDL_GetError() << endl;
		exit(0);
    }
	SDL_Rect dst;
	SDL_Rect src;
	src.x = 500;
	src.y = 500;
	src.w = engine->getScreen()->getScreenSurface()->w+500;
	src.h = engine->getScreen()->getScreenSurface()->h+500;
	dst.x = 0;
	dst.y = 0;
	SDL_BlitSurface(image, &src, engine->getScreen()->getScreenSurface(), &dst); 
}
