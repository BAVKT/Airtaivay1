#include "RTv1.h"

int main()
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_LockSurface(ecran);
    int i;
    for (i = 0;i<480;i++)
        *((unsigned int *)ecran->pixels + 640*i + i) = 0x00FF00FF;
    SDL_UnlockSurface(ecran);
    SDL_Flip(ecran);
    getchar();
    SDL_Quit();
    return 0;
}
