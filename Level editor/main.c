

#include "main.h"


int main(int argc, char *argv[])
{
	unsigned int frameLimit = SDL_GetTicks() + 16;
	int go;

   	/* Initialisation de la SDL */

	init("Level editor");

	/* Affichage des 2 layers */
	input.layerDrawn = 3;

	/* Chargement des ressources (graphismes, sons) */
	loadGame();

	/* Appelle la fonction cleanup � la fin du programme */

	atexit(cleanup);

	go = 1;


	/* Boucle infinie, principale, du jeu */

	while (go == 1)
	{

		/* On prend on compte les input (clavier, joystick... */
		getInput();

		/* On met � jour le jeu */
		update();

		/* On affiche tout */
		draw();

		/* Gestion des 60 fps (1000ms/60 = 16.6 -> 16 */
		delay(frameLimit);
		frameLimit = SDL_GetTicks() + 16;

	}

	/* Exit */

	exit(0);
}

