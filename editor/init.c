
#include "init.h"


void init(char *title)
{
	/* Initialise SDL Video */

	if (SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());

		exit(1);
	}


	jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }

	/* Titre de la fenetre */

	SDL_WM_SetCaption(title, NULL);


    /* Initialise SDL_TTF */
    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

        exit(1);
    }

    /* Charge la police en 32 points (taille) */
    font = loadFont("font/GenBasB.ttf", 32);

	//On commence par le level 1
	jeu.level = 1;


}


void loadGame(void)
{
    //On crée un tableau de 120 caractères pour contenir le nom de notre fichier
    char file[120];

	/* Si le background est déjà chargé, on ne le recharge pas */
	if (map.background == NULL)
		map.background = loadImage("graphics/background.png");

    /* si on ne peut pas, on quitte */
	if (map.background == NULL)
	{
		printf("Unable to load background");
		exit(1);
	}

    //On décharge le tileset précédent et on charge celui de la map, si nécessaire
    if (map.tileSet != NULL)
	{
		SDL_FreeSurface(map.tileSet);
	}

	sprintf(file, "graphics/tileset%d.png", jeu.level);
	map.tileSet = loadImage(file);

	if (map.tileSet == NULL)
	{
		printf("Unable to load tileset : %d", jeu.level);
		exit(1);
	}


    /* On charge la map */
    sprintf(file, "map/map%d.txt", jeu.level);
    loadMap(file);

    if(file == NULL)
    {
		printf("Unable to load map : %d", jeu.level);
		exit(1);
	}

}



void cleanup()
{

    /* Libère l'image du background */

	if (map.background != NULL)
	{
		SDL_FreeSurface(map.background);
	}


	/* Libère l'image du tileset */

	if (map.tileSet != NULL)
	{
		SDL_FreeSurface(map.tileSet);
	}

	/* Close the font */
    closeFont(font);


    /* Close SDL_TTF */
    TTF_Quit();

	/* Quitte la SDL */
	SDL_Quit();

}


