
#include "font.h"

 TTF_Font *loadFont(char *name, int size)
 {
     /* Utilise SDL_TTF pour charger la police � la taille d�sir�e */

     TTF_Font *font = TTF_OpenFont(name, size);

     if (font == NULL)
     {
         printf("Failed to open Font %s: %s\n", name, TTF_GetError());

         exit(1);
     }

     return font;
 }


 void closeFont(TTF_Font *font)
 {
     /* Ferme la police quand on n'en a plus besoin (avant de quitter) */

     if (font != NULL)
     {
         TTF_CloseFont(font);
     }
 }


 void drawString(char *text, int x, int y, TTF_Font *font)
 {
     SDL_Rect dest;
     SDL_Surface *surface;
     SDL_Color foregroundColor;

     /* On choisit d'�crire le texte en noir */
     foregroundColor.r = 0;
     foregroundColor.g = 0;
     foregroundColor.b = 0;


     /* On utilise SDL_TTF pour g�n�rer une SDL_Surface � partir d'une cha�ne de caract�res (string) */

     surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);


     if (surface == NULL)
     {
         printf("Couldn't create String %s: %s\n", text, SDL_GetError());

         return;
     }

     /* On blitte cette SDL_Surface � l'�cran */

     dest.x = x;
     dest.y = y;
     dest.w = surface->w;
     dest.h = surface->h;

     SDL_BlitSurface(surface, NULL, jeu.screen, &dest);

     /* On lib�re la SDL_Surface temporaire (pour �viter les fuites de m�moire - cf. chapitre d�di�) */
     SDL_FreeSurface(surface);
 }

