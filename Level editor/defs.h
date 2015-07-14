

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
/* On inclut les libs suppl�mentaires */
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

/* Taille de la fen�tre / r�solution en plein �cran */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* Valeur RGB pour la transparence (canal alpha) */
#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

/* Taille maxi de la map : on voit large : 400 x 300 tiles */
#define MAX_MAP_X 400
#define MAX_MAP_Y 300

/* Taille d'une tile (32 x 32 pixels) */
#define TILE_SIZE 32


/* N� de la tile transparente */
#define BLANK_TILE 0

/* MAX_TILES = num�ro de la derni�re tile */
#define MAX_TILES 17

//Nombre maximum de levels
#define LEVEL_MAX 2

