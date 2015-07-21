

#include "structs.h"

/* Prototypes des fonctions utilis�es */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);
extern void updatePlayer(void);
extern void initializePlayer(int playerNumber);
extern void updateMonsters(void);
extern void drawStartMenu(void);
extern void updateStartMenu(void);
extern void drawImage(SDL_Surface *image, int x, int y);
extern void drawPauseMenu(void);
extern void updatePauseMenu(void);
extern void drawMap(int);
extern void drawAnimatedEntity(GameObject *entity);
extern void drawHud(void);
extern void doFireballs(void);
extern void drawFireballs(void);
extern void doPlateforme(void);
extern void drawPlateforme(void);



/* D�claration des structures globales utilis�es par le jeu */

Input input;
Gestion jeu;
Map map;
GameObject player;
GameObject monster[MONSTRES_MAX];
GameObject shuriken[10];
GameObject plateforme[50];
/* D�claration de notre police de caract�res */
TTF_Font *font;

