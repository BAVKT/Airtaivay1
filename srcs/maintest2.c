#include <SDL.h>
#include "RTv1.h"

int main()
{
	SDL_Window*	win;
	SDL_Event	event;
	int			fin;

	win = NULL;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		640,480,SDL_WINDOW_SHOWN)))
		error_quit(1);
	fin = 0;
	while (!fin)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				ft_putendl("yolo");
    			fin = 1;
			}
		}
		SDL_UpdateWindowSurface(win);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
