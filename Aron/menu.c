
#include "menu.h"

void updateStartMenu(void)
{
    //Si on appuie sur BAS
    if(input.down == 1)
    {
        //Si choice = O (il est sur start), on le met à 1 (quit)
        if(jeu.choice == 0)
            jeu.choice++;

        input.down = 0;
    }

    //Si on appuie sur HAUT
    if(input.up == 1)
    {
        //Si choice = 1 (il est sur Quit), on le met à 0 (Start)
        if(jeu.choice == 1)
            jeu.choice--;

        input.up = 0;
    }

    //Si on appuie sur Enter et qu'on est sur Start, on recharge le jeu et on quitte l'état menu
    if(input.enter)
    {
         if(jeu.choice == 0)
        {
            player.checkpointActif = 0;
            jeu.level = 1;
            initializePlayer();
            changeLevel();
            /* On réinitialise les variables du jeu */
            jeu.vies = 3;
            jeu.etoiles = 0;
            jeu.onMenu = 0;
        }
        //Sinon, on quitte le jeu
        else if(jeu.choice == 1)
        {
            exit(0);
        }
        input.enter = 0;
    }


}


void drawStartMenu(void)
{

    //On crée une varuiable qui contiendra notre texte
    char text[200];

    //Le titre
    sprintf(text, "The Mystic Forest");
    drawString(text, 260, 50, font);

    //Si l'option n'est pas en surbrillance, on l'affiche normalement, sinon on rajoute ">"
    if(jeu.choice != 0)
    {
        sprintf(text, "DEMARRER");
        drawString(text, 273, 200, font);
    }
    if(jeu.choice != 1)
    {
        sprintf(text, "QUITTER");
        drawString(text, 273, 280, font);
    }

     //Si l'option est en surbrillance, on rajoute ">"
    if(jeu.choice == 0)
    {
        sprintf(text, "> DEMARRER");
        drawString(text, 250, 200, font);
    }
    else if(jeu.choice == 1)
    {
        sprintf(text, "> QUITTER");
        drawString(text, 250, 280, font);
    }
}


void updatePauseMenu(void)
{

    //Si on appuie sur Enter on quitte l'état menu
    if(input.enter)
    {
        jeu.onMenu = 0;
        input.enter = 0;
    }

}


void drawPauseMenu(void)
{
    char text[200];

    //On écrit PAUSE
    sprintf(text, "** PAUSE **");
    drawString(text, 240, 240, font);

}


