#include "RTv1.h"

int main()
{
	SDL_Event	event;
	SDL_Rect	r;
	t_b			b;
	int			fin;
	// SDL_Surface	*screen;

	b.win = NULL;
	b.winx = 1024;
	b.winy = 768;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b.win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b.winx, b.winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
	r.w = 100;
	r.h = 100;
	b.rend = SDL_CreateRenderer(b.win, -1, SDL_RENDERER_ACCELERATED);
	b.img = SDL_CreateTexture(b.rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, b.winx, b.winy);
	fin = 0;
	while (!fin)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				fin = 1;
		r.x = rand()%500;
		r.y = rand()%500;
		SDL_SetRenderTarget(b.rend, b.img);
		SDL_SetRenderDrawColor(b.rend, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(b.rend);
		SDL_RenderDrawRect(b.rend,&r);
		SDL_SetRenderDrawColor(b.rend, rand()%255, rand()%255, rand()%255, rand()%255);
		SDL_RenderFillRect(b.rend, &r);
		SDL_SetRenderTarget(b.rend, NULL);
		SDL_RenderCopy(b.rend, b.img, NULL, NULL);
		SDL_RenderPresent(b.rend);
		SDL_Delay(100);
	}
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
