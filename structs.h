
 #include "defs.h"

  /* Structures qui seront utilis�es pour g�rer le jeu */

  /* Structure pour g�rer l'input (clavier puis joystick) */

   typedef struct Input
  {

    int left, right, up, down, jump, attack, enter, erase, pause;

  } Input;


  /* Structure pour g�rer le niveau (� compl�ter plus tard) */

  typedef struct Gestion
  {

    SDL_Surface *screen;

  } Gestion;
