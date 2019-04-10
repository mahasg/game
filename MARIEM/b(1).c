
 #include <stdio.h>
#include  <stdlib.h>
 #include  <SDL/SDL.h>
 #include <SDL/SDL_image.h>
 #include <stdbool.h>
#include "b.h"

 void deplacer(SDL_Rect positionpersonage)

{

  SDL_Surface *ecran =NULL;
    SDL_Surface *image =NULL,*personage=NULL;
    SDL_Rect positionecran,positionpersonage;
    char pause;
    int continuer =1,curseur=1;

    SDL_Event event;

    image = SDL_LoadBMP("nature.bmp");
    personage=IMG_Load("detective.png");
    SDL_SetColorKey(personage, SDL_SRCCOLORKEY, SDL_MapRGB(personage->format, 255, 255, 255));
    positionecran.x=-10;
    positionecran.y=-10;
    positionpersonage.x=50;
    positionpersonage.y=200;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(994, 694, 24, SDL_HWSURFACE );
    while (continuer)
    {
     SDL_WaitEvent(&event);
        SDL_BlitSurface(image, NULL, ecran, &positionecran);
        SDL_BlitSurface(personage,NULL,ecran,&positionpersonage);
        SDL_Flip(ecran);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
        case SDLK_UP:
                positionpersonage.y=positionpersonage.y-10;
        break;
        case SDLK_DOWN:
                positionpersonage.y=positionpersonage.y+10;
        break;
            case SDLK_RIGHT:
                positionpersonage.x=positionpersonage.x+20;
                break;
            case SDLK_LEFT:
                positionpersonage.x=positionpersonage.x-20;
                break;

            }
       			break;
        case SDL_MOUSEBUTTONUP:


                positionpersonage.x=event.button.x;
                    positionpersonage.y=event.button.y;
                //SDL_BlitSurface(personage,NULL,ecran,&positionpersonage);


                    break;

        }
    }
    SDL_FreeSurface(image);
    SDL_FreeSurface(personage);

    return 0;
}

}

