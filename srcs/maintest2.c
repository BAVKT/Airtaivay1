#include "RTv1.h"

void	init_b(t_b *b)
{
	b->win = NULL;
	b->winx = 1024;
	b->winy = 768;
	b->rend = SDL_CreateRenderer(b->win, -1, SDL_RENDERER_ACCELERATED);
	b->img = SDL_CreateTexture(b->rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, b->winx, b->winy);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b->win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b->winx, b->winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
}

void	draw(t_b *b)
{
	int			x;
	int			y;

	x = rand() % 500;
	y = rand() % 500;
	SDL_SetRenderTarget(b->rend, b->img);
	SDL_SetRenderDrawColor(b->rend, rand() % 255, rand() % 255, rand() % 255, 255);
	SDL_RenderDrawPoint(b->rend, x, y);
	SDL_SetRenderTarget(b->rend, NULL);
	SDL_RenderCopy(b->rend, b->img, NULL, NULL);
	SDL_RenderPresent(b->rend);
}

int main()
{
	SDL_Event	event;
	t_b			b;
	int			fin;

	fin = 0;
	init_b(&b);
	while (!fin)
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				fin = 1;
			else
				fin = 0;
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
