#include "init.h"

   /* Fonction qui initialise le jeu */

   void init(char *title)
   {

    /* Initialise SDL Video. Si la valeur de retour est inférieure à zéro, la SDL n'a pas pu
     s'initialiser et on quite */

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


     /* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
     hauteur définies dans les defines (defs.h). On utilise aussi la mémoire vidéo
     (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
     (SDL_DOUBLEBUF) */

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0,
                                                        SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH,
                     SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);


    /* On cache le curseur de la souris */

    SDL_ShowCursor(SDL_ENABLE);

    }



   /* Fonction qui quitte le jeu proprement */

    void cleanup()
   {

      /* Quitte la SDL */
      SDL_Quit();

    }
