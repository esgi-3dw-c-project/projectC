

#include "defs.h"

/* Structures qui seront utilis�es pour g�rer le jeu */

/* Structure pour g�rer l'input (clavier puis joystick) */

typedef struct Input
{
	int left, right, up, down, add, remove;
	int previous, next, load, save, copy, reinit;
	int mouseX, mouseY;
	int leveldown, levelup;
	int layerDrawn, changeLayer;

} Input;


/* Structure pour g�rer le niveau (� compl�ter plus tard) */

typedef struct Gestion
{

    SDL_Surface *screen;
    int level;

} Gestion;


/* Structure pour g�rer la map � afficher (� compl�ter plus tard) */

typedef struct Map
{

	SDL_Surface *background, *tileSet;

	/* Coordonn�es de d�but, lorsqu'on doit dessiner la map */
	int startX, startY;

	/* Coordonn�es max de fin de la map */
	int maxX, maxY;

	/* Tableau � double dimension repr�sentant la map de tiles */
	int tile[MAX_MAP_Y][MAX_MAP_X];

	//Deuxi�me couche de tiles
	int tile2[MAX_MAP_Y][MAX_MAP_X];

} Map;


typedef struct Cursor
{
	int x, y, tileID;
} Cursor;




