#include "Menu.h"
#include "SDL_ttf.h"
#include <string.h>
#include "Engine.h"

void Menu::decSelected(){
	selected = (selected-1)%numItems; //?
	/*if(selected == 0)
		selected = numItems-1;
	else
		selected = (selected-1);*/
}
void Menu::incSelected(){
	selected = (selected+1)%numItems;	
}

TTF_Font* Menu::loadFont(const char* file, int ptsize){
	
	TTF_Font* tmpfont;
	tmpfont = TTF_OpenFont(file, ptsize);
	
	if (tmpfont == NULL){
		printf("Unable to load font: %s %s \n", file, TTF_GetError());
		exit(0);
	}
	return tmpfont;
}


SDL_Surface* Menu::drawText(TTF_Font *fonttodraw, char fgR, char fgG, char fgB, char fgA, char bgR, char bgG, char bgB, char bgA, const char text[], textquality quality)
{
	SDL_Color tmpfontcolor = {fgR,fgG,fgB,fgA};
	SDL_Color tmpfontbgcolor = {bgR, bgG, bgB, bgA};
	SDL_Surface *resulting_text;
			   
	if (quality == solid) 
		resulting_text = TTF_RenderText_Solid(fonttodraw, text, tmpfontcolor);
	
	else if (quality == shaded)
	   	resulting_text = TTF_RenderText_Shaded(fonttodraw, text, tmpfontcolor, tmpfontbgcolor);
	
	else if (quality == blended) 
		resulting_text = TTF_RenderText_Blended(fonttodraw, text, tmpfontcolor);
					 
	return resulting_text;
}


Menu::Menu(){
}
Menu::~Menu(){
	delete [] selections;
	selections = NULL;
	delete [] selectionSurface;
	selectionSurface = NULL;
}
