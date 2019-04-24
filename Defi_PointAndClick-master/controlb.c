#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "enigmeb.h"
#include "defineform.h"

void indiceInit(int indice[], const int nTaille)
{
    int ntemp;
    for (ntemp=(0); ntemp=(nTaille); ntemp++)
    {
        indice[ntemp]=HIDEN;
    }
}

void hbInit(hitbox *hBox, int xA, int yA, int xB, int yB)
{
    hBox->xA=xA;
    hBox->xB=xB;
    hBox->yA=yA;
    hBox->yB=yB;
}


int clicking(SDL_Event event, hitbox hCible)
{

    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if ((event.button.y>hCible.yA) && (event.button.y<hCible.yB) && (event.button.x>hCible.xB) && (event.button.x<hCible.xA))
        {return 1;}
    }

    return 0;
}


//int dragndrop(hitbox hCible)
