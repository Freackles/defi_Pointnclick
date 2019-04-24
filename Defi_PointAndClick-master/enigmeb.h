#ifndef ENIGMEB_H_INCLUDED
#define ENIGMEB_H_INCLUDED

#pragma once


//macro
#define HIDEN 0
#define FIND 1

#define SCMAX 5
#define SLMAX 6

#define W_WIDTH 1280
#define W_HEIGHT 720

//type
typedef struct hitbox
{
    int xA, xB;
    int yA, yB;
}hitbox;


//prototype control
extern void indiceInit(int indice[], const int nTaille);
extern void hbInit(hitbox *hBox, int xA, int yA, int xB, int yB);
extern int clicking(SDL_Event event, hitbox hCible);

//prototype affichage
extern void GestionImage(SDL_Renderer *rend, char cSource[], hitbox hbox);
extern void ScAffichage (SDL_Renderer *rend, int tIndice[], hitbox hboxes[]);
extern void SLAffichage (SDL_Renderer *rend, int tIndice[], hitbox hboxes[]);


//prototype enigmes
extern int scene_crime(SDL_Event event,SDL_Renderer *rend, int tIndice[]);
extern int scene_lettre(SDL_Event event,SDL_Renderer *rend, int tIndice[]);


#endif // ENIGMEB_H_INCLUDED
