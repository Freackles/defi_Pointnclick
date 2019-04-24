#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "enigmeb.h"
#include "defineform.h"

//macro



/** \brief 1er ennigme par brayan.
 *         Ici, le joueur doit touver tous les indices sur la scène du crime.
 *
 * \param SDL_Event event
 * \param Tableau de booleen permettant de valider si le joueur a retrouver tout les indices
 * \return 1 si l'enigme est resolu, 0 si ce n'est pas la cas
 *
 */
int scene_crime(SDL_Event event,SDL_Renderer *rend, int tIndice[])
{
    hitbox hBox[SCMAX];

    //initialisation des hitboxes
    hbInit(&hBox[0], 629, 481, 680, 534);
    hbInit(&hBox[1], 748, 871, 485, 590);
    hbInit(&hBox[2], 20, 44, 68, 575);
    hbInit(&hBox[3], 760, 323, 917, 426);
    hbInit(&hBox[4], 1060, 439, 1104, 473);

    //verification des clics
    int nTemp;
    for(nTemp=0;nTemp<SCMAX; nTemp++)
    {
        if((clicking(event, hBox[nTemp])==1) && (tIndice[nTemp]==HIDEN))
        {
            tIndice[nTemp]=FIND;
        }
    }


    //verification de tout les indices
    int nTest;
    int nValidate=0;
    for (nTest=0; nTest<SCMAX; nTest++)
    {
        if (tIndice[nTest]==FIND)
            nValidate+=1;
    }

    //affichage
    ScAffichage(rend, tIndice, hBox);

    if (nValidate == SCMAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/** \brief 2eme énigme par Brayan
 *          ici, le joueur dois remettre dans l'ordre une lettre retrouvé en 6 morceaux
 *
 * \param
 * \param
 * \return
 *
 */
int scene_lettre(SDL_Event event,SDL_Renderer *rend, int tIndice[])
{
    hitbox hBox[SLMAX];

    //initialisation des hitboxes
    hbInit(&hBox[0], 360, 96, 451, 122);
    hbInit(&hBox[1], 293, 294, 535, 325);
    hbInit(&hBox[2], 80, 333, 483, 367);
    hbInit(&hBox[3], 98, 368, 297, 401);
    hbInit(&hBox[4], 560, 327, 675, 365);
    hbInit(&hBox[5], 79, 608, 0334, 640);

    //verification des clics
    int nTemp;
    for(nTemp=0;nTemp<SLMAX; nTemp++)
    {
        if((clicking(event, hBox[nTemp])==1) && (tIndice[nTemp]==HIDEN))
        {
            tIndice[nTemp]=FIND;
        }
    }

    //verification de tout les indices
    int nTest;
    int nValidate=0;
    for (nTest=0; nTest<SLMAX; nTest++)
    {
        if (tIndice[nTest]==FIND)
            nValidate+=1;
    }

    //affichage
    SLAffichage(rend, tIndice, hBox);

    if (nValidate == SLMAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
