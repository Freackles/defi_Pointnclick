#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

#include "defineform.h"
#include "enigmeb.h"

void GestionImage(SDL_Renderer *rend, char cSource[], hitbox hbox)
{
        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;
        SDL_Surface *surface;
        SDL_Texture *texture;


        surface = IMG_Load(cSource);//Chargement de l'image png

        if(!surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(surface)
        {
            texture = SDL_CreateTextureFromSurface(rend,surface); // Préparation du sprite
            SDL_FreeSurface(surface); // Libération de la ressource occupée par le sprite

            if(texture)
            {
                rectangleSource.x=0;
                rectangleSource.y=0;
                rectangleSource.w=hbox.xB-hbox.xA;
                rectangleSource.h=hbox.yB-hbox.yA;

                SDL_QueryTexture(texture,NULL,NULL,NULL,NULL);

                //Définition du rectangle dest pour dessiner Bitmap
                rectangleDest.x=hbox.xA;//debut x
                rectangleDest.y=hbox.yA;//debut y
                rectangleDest.w=rectangleSource.w; //Largeur
                rectangleDest.h=rectangleSource.h; //Hauteur

                SDL_RenderCopy(rend,texture,&rectangleSource,&rectangleDest);
                SDL_RenderPresent(rend); // Affichage
                SDL_RenderClear(rend);
            }

            else
            {
                fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
            }

        }
        else
        {
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }

    //Destroy texture
    if(texture!=NULL)
            SDL_DestroyTexture(texture);

}




void ScAffichage (SDL_Renderer *rend, int tIndice[], hitbox hboxes[])
{
    hitbox hbox;

    hbInit(&hbox, 0, 0, W_WIDTH, W_HEIGHT);
    //background
    GestionImage(rend, "./assetb/crimescene.jpg", hbox);

    //highlight des indices déjà obtenue
    int nTemp;
    for (nTemp=0; nTemp=5; nTemp++)
    {
        if (tIndice[nTemp]==FIND)
        {
            GestionImage(rend, "./assetb/checkmark.png", hboxes[nTemp]);
        }
    }

}


void SLAffichage (SDL_Renderer *rend, int tIndice[], hitbox hboxes[])
{
    hitbox hbox;

    //backgrounds
    hbInit(&hbox, 0, 0, 733, W_HEIGHT);
    GestionImage(rend, "./assetb/crimescene.jpg", hbox);

    //hbInit(&hbox, 0, 0, W_WIDTH, W_HEIGHT);
    //GestionImage(surface, texture, rend, "./assetb/bg.jpg", hbox);

    //highlight des indices déjà obtenue
    int nTemp;
    for (nTemp=0; nTemp=5; nTemp++)
    {
        if (tIndice[nTemp]==FIND)
        {
            GestionImage(rend, "./assetb/checkmark.png", hboxes[nTemp]);
        }
    }

}
