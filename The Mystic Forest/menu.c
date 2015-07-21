
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
            initializePlayer(1);
            changeLevel();
            /* On réinitialise les variables du jeu */
            jeu.vies = player.playerNumber;
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
    drawString(text, 200, 50, font);

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

    //Copyright
    sprintf(text, "Projet C - Groupe 7");
    drawString(text, 20, 420, font);
}
void updatePlayerMenu(void)
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
            initializePlayer(player.playerNumber++);
            changeLevel();
            /* On réinitialise les variables du jeu */
            jeu.vies = player.playerNumber;
            jeu.etoiles = 0;
            jeu.onMenu = 0;
            if(player.playerNumber == 1)
            {
                jeu.HUD_vie = loadImage2("graphics/life.png");
            }
            else if(player.playerNumber == 2)
            {
                jeu.HUD_vie = loadImage2("graphics/life2.png");
            }
            else if(player.playerNumber == 3)
            {
                jeu.HUD_vie = loadImage2("graphics/life3.png");
            }
            else
            {
                jeu.HUD_vie = loadImage2("graphics/life4.png");
            }
        }
        //Sinon, on quitte le jeu
        else if(jeu.choice == 1)
        {
            exit(0);
        }
        input.enter = 0;
    }


}

void drawPlayerMenu(void)
{

    //On crée une varuiable qui contiendra notre texte
    char text[200];

    //Le titre
    sprintf(text, "The Mystic Forest");
    drawString(text, 200, 50, font);

    sprintf(text, "PLAYER %d", player.playerNumber);
    drawString(text, 20, 320, font);

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

    //Copyright
    sprintf(text, "Projet C - Groupe 7");
    drawString(text, 20, 420, font);
}

void updateScoreMenu(void)
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
            initializePlayer(1);
            changeLevel();
            /* On réinitialise les variables du jeu */
            jeu.vies = player.playerNumber;
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

void drawScoreMenu(void)
{

    //On crée une varuiable qui contiendra notre texte
    char text[200];

    //Le titre
    sprintf(text, "The Mystic Forest - Scores");
    drawString(text, 100, 50, font);

    sprintf(text, "PLAYER 1 : %d", jeu.etoiles);
    drawString(text, 200, 100, font);

    sprintf(text, "PLAYER 2 : %d", jeu.etoiles2);
    drawString(text, 200, 130, font);

    sprintf(text, "PLAYER 3 : %d", jeu.etoiles3);
    drawString(text, 200, 160, font);

    sprintf(text, "PLAYER 4 : %d", jeu.etoiles4);
    drawString(text, 200, 190, font);

    //Si l'option n'est pas en surbrillance, on l'affiche normalement, sinon on rajoute ">"
    if(jeu.choice != 0)
    {
        sprintf(text, "DEMARRER");
        drawString(text, 273, 250, font);
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
        drawString(text, 250, 250, font);
    }
    else if(jeu.choice == 1)
    {
        sprintf(text, "> QUITTER");
        drawString(text, 250, 280, font);
    }

    //Copyright
    sprintf(text, "Projet C - Groupe 7");
    drawString(text, 20, 420, font);
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


