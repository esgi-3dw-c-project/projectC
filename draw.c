
#include "draw.h"


  void draw(void)
  {
    SDL_Surface *imageDeFond = NULL;
    imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);
    SDL_BlitSurface(imageDeFond, NULL, jeu.screen, &positionFond);
    /* Affiche l'écran */

    SDL_Flip(jeu.screen);


    /* Delai */

    SDL_Delay(1);

  }



  void delay(unsigned int frameLimit)
  {

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
  }
