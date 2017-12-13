#include "RTv1.h"

void	init_b(t_b *b)
{
	b->win = NULL;
	b->winx = 1024;
	b->winy = 768;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b->win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b->winx, b->winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
	b->img = SDL_GetWindowSurface(b->win);
}

void	draw(t_b *b)
{
	int			x;
	int			y;
	int			i;
	int			j;
	int 		color;

	x = rand() % b->winx;
	y = rand() % b->winy;
	i = 0;
	color = rand() % INT_MAX;
	while (i++ < x)
	{	
		j = 0;
		while (j++ < y)
			*((unsigned int *)b->img->pixels + y * i + j) = color * 1;;
	}
	SDL_UpdateWindowSurface(b->win);
	// SDL_Delay(1000);
}

int main()
{
	SDL_Event	event;
	t_b			b;
	int			fin;

	fin = 0;
	init_b(&b);
	while (!fin)
	{
		while (SDL_PollEvent(&event))
			if (event.type == SDL_QUIT)
				fin = 1;
		draw(&b);
	}
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
