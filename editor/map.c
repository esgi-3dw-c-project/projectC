
#include "map.h"


void loadMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "rb");

	/* Si on ne peut pas ouvrir le fichier, on quitte */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}

	/* Lit les donn�es du fichier dans la map */

	map.maxX = map.maxY = 0;

	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			/* On lit le num�ro de la tile et on le copie dans notre tableau */
			fscanf(fp, "%d", &map.tile[y][x]);

			/* Permet de d�terminer la taille de la map (voir plus bas) */
			if (map.tile[y][x] > 0)
			{
				if (x > map.maxX)
				{
					map.maxX = x;
				}

				if (y > map.maxY)
				{
					map.maxY = y;
				}
			}
		}
	}

	//Deuxi�me couche de tiles
	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			/* On lit le num�ro de la tile et on le copie dans notre tableau */
			fscanf(fp, "%d", &map.tile2[y][x]);
		}
	}


	/* On change ces coordonn�es pour qu'on puisse scroller et �diter la map
	au maximum */

	map.maxX = MAX_MAP_X * TILE_SIZE;
	map.maxY = MAX_MAP_Y * TILE_SIZE;


	/* Remet � 0 les coordonn�es de d�part de la map */

	map.startX = map.startY = 0;


	/* Et on referme le fichier */

	fclose(fp);

}


void saveMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "wb");

	/* Si on ne peut pas charger la map, on quitte */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}


    /* Sauvegarde la map : couche 1 */
	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fprintf(fp, "%d ", map.tile[y][x]);
		}

		fprintf(fp, "\n");
	}

	/* Sauvegarde la map : couche 2 */
	for (y=0;y<MAX_MAP_Y;y++)
	{
		for (x=0;x<MAX_MAP_X;x++)
		{
			fprintf(fp, "%d ", map.tile2[y][x]);
		}

		fprintf(fp, "\n");
	}


	/* On referme le fichier */

	fclose(fp);
}


void reinitMap(char *name)
{
	int x, y;
	FILE *fp;

	fp = fopen(name, "wb+");

	/* Si on ne peut pas charger la map, on quitte */

	if (fp == NULL)
	{
		printf("Failed to open map %s\n", name);

		exit(1);
	}


	/* Remplit la map de 0 */
	for (y=0;y<MAX_MAP_Y;y++)
    {
        for (x=0;x<MAX_MAP_X;x++)
        {
            fprintf(fp, "0 ");
        }

        fprintf(fp, "\n");
    }

    for (y=0;y<MAX_MAP_Y;y++)
    {
        for (x=0;x<MAX_MAP_X;x++)
        {
            fprintf(fp, "0 ");
        }

        fprintf(fp, "\n");
    }


	/* On referme le fichier */

	fclose(fp);
}




void drawMap(void)
{
	int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

	/* On initialise mapX � la 1�re colonne qu'on doit blitter.
	Celle-ci correspond au x de la map (en pixels) divis�s par la taille d'une tile (32)
    pour obtenir la bonne colonne de notre map
    Exemple : si x du d�but de la map = 1026, on fait 1026 / 32
    et on sait qu'on doit commencer par afficher la 32eme colonne de tiles de notre map */
	mapX = map.startX / TILE_SIZE;

	/* Coordonn�es de d�part pour l'affichage de la map : permet
	de d�terminer � quels coordonn�es blitter la 1�re colonne de tiles au pixel pr�s
	(par exemple, si la 1�re colonne n'est visible qu'en partie, on devra commencer � blitter
	hors �cran, donc avoir des coordonn�es n�gatives - d'o� le -1). */
	x1 = (map.startX % TILE_SIZE) * -1;

	/* Calcul des coordonn�es de la fin de la map : jusqu'o� doit-on blitter ?
	Logiquement, on doit aller � x1 (d�part) + SCREEN_WIDTH (la largeur de l'�cran).
	Mais si on a commenc� � blitter en dehors de l'�cran la premi�re colonne, il
	va falloir rajouter une autre colonne de tiles sinon on va avoir des pixels
	blancs. C'est ce que fait : x1 == 0 ? 0 : TILE_SIZE qu'on pourrait traduire par:
	if(x1 != 0)
        x2 = x1 + SCREEN_WIDTH + TILE_SIZE , mais forc�ment, c'est plus long ;)*/
	x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

    /* On fait exactement pareil pour calculer y */
	mapY = map.startY / TILE_SIZE;
	y1 = (map.startY % TILE_SIZE) * -1;
	y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    //Si input.layerDrawn vaut 1, ou 3, on affiche la layer 1 :
    if(input.layerDrawn == 1 || input.layerDrawn == 3)
    {
        /* Dessine la carte en commen�ant par startX et startY */

        /* On dessine ligne par ligne en commen�ant par y1 (0) jusqu'� y2 (480)
        A chaque fois, on rajoute TILE_SIZE (donc 32), car on descend d'une ligne
        de tile (qui fait 32 pixels de hauteur) */
        for (y = y1; y < y2; y += TILE_SIZE)
        {
            /* A chaque d�but de ligne, on r�initialise mapX qui contient la colonne
            (0 au d�but puisqu'on ne scrolle pas) */
            mapX = map.startX / TILE_SIZE;

            /* A chaque colonne de tile, on dessine la bonne tile en allant
            de x = 0 � x = 640 */
            for (x = x1; x < x2; x += TILE_SIZE)
            {

                /* Suivant le num�ro de notre tile, on d�coupe le tileset (a = le num�ro
                de la tile */
                a = map.tile[mapY][mapX];

                /* Calcul pour obtenir son y (pour un tileset de 10 tiles
                par ligne, d'o� le 10 */
                ysource = a / 10 * TILE_SIZE;
                /* Et son x */
                xsource = a % 10 * TILE_SIZE;

                /* Fonction qui blitte la bonne tile au bon endroit */
                drawTile(map.tileSet, x, y, xsource, ysource);

                mapX++;
            }

            mapY++;
        }
    }


    mapX = map.startX / TILE_SIZE;
	mapY = map.startY / TILE_SIZE;


    //Si input.layerDrawn vaut 2, ou 3, on affiche la layer 2 :
    if(input.layerDrawn == 2 || input.layerDrawn == 3)
    {
        //Deuxi�me couche de tiles ;)
        for (y = y1; y < y2; y += TILE_SIZE)
        {
            mapX = map.startX / TILE_SIZE;

            for (x = x1; x < x2; x += TILE_SIZE)
            {
                a = map.tile2[mapY][mapX];
                ysource = a / 10 * TILE_SIZE;
                xsource = a % 10 * TILE_SIZE;
                drawTile(map.tileSet, x, y, xsource, ysource);
                mapX++;
            }
            mapY++;
        }
    }

        /* On affiche la tile s�lectionn�e � c�t� du curseur */
        ysource = cursor.tileID / 10 * TILE_SIZE;
        xsource = cursor.tileID % 10 * TILE_SIZE;
        drawTile(map.tileSet, cursor.x, cursor.y, xsource, ysource);



}

