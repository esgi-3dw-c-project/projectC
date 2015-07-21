

#include "main.h"


int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go, i;

   	/* Initialisation de la SDL */
	init("Aron");

	/* On initialise le joueur */
	initializePlayer(1);

	/* Chargement des ressources (graphismes, sons) */
	loadGame();

	/* Appelle la fonction cleanup à la fin du programme */
	atexit(cleanup);

	go = 1;


	/* Boucle infinie, principale, du jeu */


	while (go == 1)
	{
		/* On prend en compte les input (clavier, joystick... */
		getInput();

        //Si on n'est pas dans un menu
        if(jeu.onMenu == 0)
        {
            /* On met à jour le jeu */
            updatePlayer();
            doFireballs();
            updateMonsters();
            doPlateforme();
        }
        else
        {
            if(jeu.menuType == START)
                updateStartMenu();
            else if(jeu.menuType == PAUSE)
                updatePauseMenu();
            else if(jeu.menuType == PLAYER)
                updatePlayerMenu();
        }


        //Si on n'est pas dans un menu
        if(jeu.onMenu == 0)
        {
            /* On affiche tout */
            draw();
        }
        else
        {
            if(jeu.menuType == START)
            {
                drawImage(map.background, 0, 0);
                drawStartMenu();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }
            else if(jeu.menuType == PAUSE)
            {
                drawImage(map.background, 0, 0);
                drawMap(1);
                drawAnimatedEntity(&player);
                for(i = 0 ; i < jeu.nombreMonstres ; i++)
                {
                    drawAnimatedEntity(&monster[i]);
                }
                drawPlateforme();
                drawFireballs();
                drawMap(2);
                drawHud();
                drawPauseMenu();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }
            else if(jeu.menuType == PLAYER)
            {
                drawImage(map.background, 0, 0);
                drawPlayerMenu();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }

        }


		/* Gestion des 60 fps (1000ms/60 = 16.6 -> 16 */
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;
	}
	/* Exit */
	exit(0);
}

