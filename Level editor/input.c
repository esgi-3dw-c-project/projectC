

#include "input.h"


void getInput(void)
{
	SDL_Event event;

	/* Keymapping : g�re les appuis sur les touches et les enregistre
	dans la structure input */

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{

			case SDL_QUIT:
                exit(0);
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						exit(0);
					break;

					case SDLK_LEFT:
						input.left = 1;
					break;

					case SDLK_RIGHT:
						input.right = 1;
					break;

					case SDLK_UP:
						input.up = 1;
					break;

					case SDLK_DOWN:
						input.down = 1;
					break;

					/* La touche S sauvegardera */
					case SDLK_s:
						input.save = 1;
					break;

					/* La touche L chargera la map */
					case SDLK_l:
						input.load = 1;
					break;

					/* La touche DEL/Suppr r�initialisera la map */
					case SDLK_DELETE:
						input.reinit = 1;
					break;

					case SDLK_F1:
						input.levelup = 1;
					break;

					case SDLK_F2:
						input.leveldown = 1;
					break;

					case SDLK_F3:
						input.changeLayer = 1;
					break;

					default:
					break;
				}
			break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						input.left = 0;
					break;

					case SDLK_RIGHT:
						input.right = 0;
					break;

					case SDLK_UP:
						input.up = 0;
					break;

					case SDLK_DOWN:
						input.down = 0;
					break;


					default:
					break;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
				{
					/* Le clic gauche de la souris ajoutera la tile en cours */
					case SDL_BUTTON_LEFT:
						input.add = 1;
					break;

					/* Le clic central de la souris effacera la tile s�lectionn�e */
					case SDL_BUTTON_MIDDLE:
						input.remove = 1;
					break;

					/* Le clic droit de la souris copiera la tile s�lectionn�e */
					case SDL_BUTTON_RIGHT:
						input.copy = 1;
					break;

					/* La roue de la souris fera d�filer les tiles */
					case SDL_BUTTON_WHEELUP:
                        input.next = 1;
                    break;

                    case SDL_BUTTON_WHEELDOWN:
                        input.previous = 1;
                    break;


					default:
					break;
				}
			break;

			case SDL_MOUSEBUTTONUP:
				switch(event.button.button)
				{
					case SDL_BUTTON_LEFT:
						input.add = 0;
					break;

					case SDL_BUTTON_MIDDLE:
						input.remove = 0;
					break;

                    default:
					break;
				}
			break;
		}
	}

	/* Enregistre les coordonn�es de la souris */

	SDL_GetMouseState(&input.mouseX, &input.mouseY);

	/* Cette s�rie d'op�rations permet d'obtenir les coordonn�es exactes de chaque
	tile, tandis que la souris r�agit au pixel pr�s */

	input.mouseX /= TILE_SIZE;
	input.mouseY /= TILE_SIZE;

	input.mouseX *= TILE_SIZE;
	input.mouseY *= TILE_SIZE;
}



void update(void)
{

    /* Pour l'affichage du curseur (indiquant la tile � copier, mais on reviendra dessus
    dans la fonction draw() ), on r�cup�re les coordonn�es de la souris */

    cursor.x = input.mouseX;
	cursor.y = input.mouseY;

	char file[120];


    /* Gestion de notre scrolling du chapitre pr�c�dent */
 	if (input.left == 1)
	{
		map.startX -= TILE_SIZE;

		if (map.startX < 0)
		{
			map.startX = 0;
		}
	}

	else if (input.right == 1)
	{
		map.startX += TILE_SIZE;

		if (map.startX + SCREEN_WIDTH >= map.maxX)
		{
			map.startX = map.maxX - SCREEN_WIDTH;
		}
	}

	if (input.up == 1)
	{
		map.startY -= TILE_SIZE;

		if (map.startY < 0)
		{
			map.startY = 0;
		}
	}

	else if (input.down == 1)
	{
		map.startY += TILE_SIZE;

		if (map.startY + SCREEN_HEIGHT >= map.maxY)
		{
			map.startY = map.maxY - SCREEN_HEIGHT;
		}
	}

	//Gestion du passage d'une map � l'autre
	if (input.levelup == 1)
	{
		jeu.level++;
		if (jeu.level > LEVEL_MAX )
            jeu.level = 1;
        loadGame();

		input.levelup = 0;
	}

	if (input.leveldown == 1)
	{
		jeu.level--;
		if (jeu.level < 1 )
            jeu.level = LEVEL_MAX;
        loadGame();

		input.leveldown = 0;
	}

    /* Gestion de la copie de tile :
    on retrouve les coordonn�es de la tile point�e par la souris et on remplace
    sa valeur par celle de la tile s�lectionn�e dans le curseur */

    if (input.add == 1)
	{

	    if ( input.layerDrawn == 1 )
		map.tile[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = cursor.tileID;
        else if ( input.layerDrawn == 2 )
		map.tile2[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = cursor.tileID;

	}

	/* M�me fonctionnement, sauf qu'on r�initialise la tile point�e en lui donnant
	la valeur BLANK_TILE (0 par d�faut) */

	else if (input.remove == 1)
	{

		if ( input.layerDrawn == 1 )
		map.tile[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = BLANK_TILE;
        else if ( input.layerDrawn == 2 )
		map.tile2[(map.startY + cursor.y) / TILE_SIZE][(map.startX + cursor.x) / TILE_SIZE] = BLANK_TILE;

		cursor.tileID = 0;
	}

    /* On fait d�filer les tiles dans un sens ou dans l'autre */

	if (input.previous == 1)
	{
		cursor.tileID--;

        if (cursor.tileID < 0)
        {
            cursor.tileID = MAX_TILES - 1;
        }
        else if (cursor.tileID > MAX_TILES)
        {
            cursor.tileID = 0;
        }


		input.previous = 0;
	}

	if (input.next == 1)
	{
		cursor.tileID++;

        if (cursor.tileID < 0)
        {
            cursor.tileID = MAX_TILES - 1;
        }
        else if (cursor.tileID > MAX_TILES)
        {
            cursor.tileID = 0;
        }

		input.next = 0;
	}

    /* On copie le num�ro de la tile point�e dans le curseur pour qu'il affiche et colle
    d�sormais cette tile */

    if (input.copy == 1)
	{
	    if ( input.layerDrawn == 1 )
		cursor.tileID = map.tile[(map.startY + cursor.y) / TILE_SIZE] [(map.startX + cursor.x) / TILE_SIZE];
        else if ( input.layerDrawn == 2 )
		cursor.tileID = map.tile2[(map.startY + cursor.y) / TILE_SIZE] [(map.startX + cursor.x) / TILE_SIZE];

		input.copy = 0;
	}

    /* Pour r�initialiser la map, on appelle la fonction reinitMap puis on recharge la map */

    if (input.reinit == 1)
	{
	    sprintf(file, "map/map%d.txt", jeu.level);
		reinitMap(file);
		loadMap(file);

		input.reinit = 0;
	}

    /* Sauvegarde la map (cf. plus loin) */

	if (input.save == 1)
	{
		sprintf(file, "map/map%d.txt", jeu.level);
		saveMap(file);

		input.save = 0;
	}

    /* Charge la map */

	if (input.load == 1)
	{
        sprintf(file, "map/map%d.txt", jeu.level);
		loadMap(file);

		input.load = 0;
	}

	if (input.changeLayer == 1)
	{
		input.layerDrawn++;
		if ( input.layerDrawn > 3 )
            input.layerDrawn = 1;

		input.changeLayer = 0;
	}

	/* On rajoute un d�lai entre 2 tours de boucle pour que le scrolling soit moins rapide */

	if (input.left == 1 || input.right == 1 || input.up == 1 || input.down == 1)
	{
		SDL_Delay(30);
	}

}

