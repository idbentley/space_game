#ifndef	MENU_H
#define MENU_H
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

#define SMALLFONTSIZE 20
#define BIGFONTSIZE 24
#define HUGEFONTSIZE 30

using namespace std;

enum textquality {solid, shaded, blended};

class Menu {
	private:
	protected:
		int numItems;
		string *menuItems;
		int selected;
		string *selections;
		TTF_Font* bigMenuFont;
		TTF_Font* menuFont;
		TTF_Font* titleFont;
		SDL_Surface **selectionSurface;
	public:

		Menu();
		virtual ~Menu();

		//Executes the highlighted command
		virtual void execCommand()=0;
		//Render menu
		virtual void renderMenu()=0;
		
		//TTF libraries
		TTF_Font * loadFont (const char* file, int ptsize);
		SDL_Surface *drawText(TTF_Font *fonttodraw, char fgR, char fgG, char fgB, char fgA, 
						char bgR, char bgG, char bgB, char bgA, const char text[], textquality quality);

		/*
		 * Getters and Setters
		 */
		int getNumItems(){ return numItems; }
		void setNumItems(int nI){ numItems = nI; }
		int getSelected(){ return selected; }
		void setSelected(int s){ selected = s; }
		void decSelected();
		void incSelected();
};
#endif
