#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main (int argc, char **argv)
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *link[3] = {NULL};

    SDL_Event event;
    SDL_Rect positionLink;

    int i = 0, continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(500, 350, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("animPerso", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    link[0] = IMG_Load("link0.PNG");
    link[1] = IMG_Load("link1.PNG");
    link[2] = IMG_Load("link2.PNG");

    SDL_SetColorKey(link[i], SDL_SRCCOLORKEY, SDL_MapRGB(link[i]->format, 32, 156, 0));

    positionLink.x = 0;
    positionLink.y = 0;

    SDL_BlitSurface(link[i], NULL, ecran, &positionLink);

    SDL_EnableKeyRepeat(100,100);

    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer = 0;
              break;

            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:

                  if(i >= 2)
                 i = 0;
                positionLink.x += 3;
                 i++;
                break;
              case SDLK_LEFT:

                  if(i <= 2)
                 i = 0;
                positionLink.x -= 3;
                 i++;

            } break;
            }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

        SDL_SetColorKey(link[i], SDL_SRCCOLORKEY, SDL_MapRGB(link[i]->format, 32, 156, 0));

        SDL_BlitSurface(link[i], NULL, ecran, &positionLink);

        SDL_Flip(ecran);
    }

    for(i = 0; i < 2; i++)
        SDL_FreeSurface(link[i]);

    SDL_Quit();

    return EXIT_SUCCESS;
}
