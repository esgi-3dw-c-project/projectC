

#include "defs.h"

/* Structures qui seront utilisées pour gérer le jeu */

/* Structure pour gérer l'input (clavier puis joystick) */

typedef struct Input
{
	int left, right, up, down, jump, attack, enter, erase, pause;
} Input;


/* Structure pour gérer le niveau (à compléter plus tard) */

typedef struct Gestion
{

    int level;
    int plyaerNumber;
    SDL_Surface *screen;
    int nombreMonstres;
    int nombreFireballs;
    int nombrePlateformes;

    //HUD
	SDL_Surface *HUD_vie, *HUD_etoiles, *Shuriken_image, *plateforme;
    int vies, etoiles;

    //Sons
    Mix_Music  *musique;

    //Sounds Fx
    Mix_Chunk  *bumper_sound, *destroy_sound, *jump_sound, *star_sound;

    //Gestion des menus
    int onMenu, menuType, choice;


} Gestion;


/* Structure pour gérer la map à afficher (à compléter plus tard) */

typedef struct Map
{

	SDL_Surface *background, *tileSet;
	SDL_Surface *tileSetB;

	/* Coordonnées de début, lorsqu'on doit dessiner la map */
	int startX, startY;

	/* Coordonnées max de fin de la map */
	int maxX, maxY;

	/* Tableau à double dimension représentant la map de tiles */
	int tile[MAX_MAP_Y][MAX_MAP_X];

	//Deuxième couche de tiles
    int tile2[MAX_MAP_Y][MAX_MAP_X];

	/* Timer et numéro du tileset à afficher pour animer la map */
	int mapTimer, tileSetNumber;

} Map;


/* Structure pour gérer notre héros */

typedef struct GameObject
{
    //Sprite du héros
	SDL_Surface *sprite;

	//Points de vie/santé
	int life, invincibleTimer;

    int playerNumber;
	/* Coordonnées du héros */
	int x, y;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	/* Largeur, hauteur du sprite */
	int h, w;

	//Checkpoint
	int checkpointActif;
	int respawnX, respawnY;

	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
	int etat, direction;

	/* Variables utiles pour la gestion des collisions */
	int onGround, timerMort;
	float dirX, dirY;
	int saveX, saveY;

	//Variable pour le double saut
	int jump;

    //Nouvelles variables pour gérer les plateformes flottantes
    int beginX, beginY;
    int type, player_dessus;


} GameObject;


