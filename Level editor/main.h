

#include "structs.h"

/* Prototypes des fonctions utilis�es */

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void draw(void);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);

extern void update(void);


/* D�claration des structures globales utilis�es par le jeu */

Input input;
Gestion jeu;
Map map;

Cursor cursor;

/* D�claration de notre police de caract�res */
TTF_Font *font;

