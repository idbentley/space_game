#include "MainMenu.h"
MainMenu::MainMenu(){
	numItems = NUMITEMS;
	selections = new string [numItems];	
	selectionSurface = new SDL_Surface *[numItems*2];
	selections[BEGIN] = "BEGIN";
	selections[OPTIONS] = "OPTIONS";
	selections[EXIT] = "EXIT";
		
	for (int i = 0; i < numItems*2; i++){
		selectionSurface[i] = NULL;
	}

	selected = BEGIN;
	
	menuFont = loadFont("fonts/SFElectrotome.ttf", SMALLFONTSIZE);			//Find a way to not hard code this... OpenFont in loadFont requires const char*
	bigMenuFont = loadFont("fonts/SFElectrotomeBold.ttf", BIGFONTSIZE);
	titleFont = loadFont("fonts/SFElectrotomeBold.ttf", HUGEFONTSIZE);
	initMenuOptionsVisuals();
	optionsMenu = new OptionMenu(this);

}
MainMenu::~MainMenu(){
}
void MainMenu::initMenuOptionsVisuals(){
	for (int i = 0; i < numItems; i++){
		selectionSurface[i] = drawText(menuFont, 255, 255, 255, 255, 0, 0, 0, 255, selections[i].c_str() , solid); 
		if (selectionSurface[i] == NULL){
			cout << "Could not init selectionSurface " << i << endl;
			exit(0);
		}
		selectionSurface[i+numItems] = drawText(bigMenuFont, 255, 100, 100, 255, 0, 0, 0, 255, selections[i].c_str(), solid);
		if(selectionSurface[i+numItems] == NULL){
			cout << "Could not init selectionSurface " << i+numItems << endl;
		}
	}
}
void MainMenu::execCommand(){
	Engine *engine = Engine::getInstance();
	switch(getSelected()){
			case BEGIN:
				engine->setGameState(GAME);
				break;
			case OPTIONS:
				engine->setCurMenu(optionsMenu);
				break;
			case EXIT:
				exit(0);
				break;
			default:
				break;
	}
}

void MainMenu::renderMenu(){
	Engine* engine = Engine::getInstance();
	//Blit the getImage() to the backbuffer
	SDL_Rect dest;
	for(int i = 0; i < numItems; i++){
		int j = i;
		if(selected == i)
			j = i + numItems;
		dest.x = (double)(engine->getScreen())->getScreenSurface()->w/2.0 - (double)selectionSurface[j]->w/2.0;
		dest.y = (double)(engine->getScreen())->getScreenSurface()->h/2.0 - (double)selectionSurface[j]->h/2.0 + (i-1)*3*SMALLFONTSIZE;
		dest.w = selectionSurface[j]->w;
		dest.h = selectionSurface[j]->h;
		SDL_BlitSurface(selectionSurface[j], NULL, (engine->getScreen())->getScreenSurface(), &dest);
	}
	SDL_Surface *title = drawText(titleFont, 100, 255, 100, 255, 0, 0, 0, 255, "Space Game", solid);
	dest.x = (double)(engine->getScreen())->getScreenSurface()->w/2.0 - (double)title->w/2.0;
	dest.y = 30;
	dest.w = title->w;
	dest.h = title->h;
	SDL_BlitSurface(title, NULL, (engine->getScreen())->getScreenSurface(), &dest);
	//Flip the backbuffer to the primary
	SDL_Flip((engine->getScreen())->getScreenSurface());
}
