#include "RTv1.h"

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
			*((unsigned int *)b->img->pixels + y * i + j) = color * 1;
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

void	ray(t_b *b)
{
	*b->vp.upleft = vect_sub(vect_add(b->cam.pos, vect_add(vect_multnb(&b->cam.dir, b->vp.dist),
		vect_multnb(&b->cam.dirup, b->vp.h / 2))), vect_multnb(&b->cam.dirright, b->vp.w / 2));
//Version presque OP je pense
//b->vp.upleft = b->cam.pos + ((b->cam.dir * b->vp.dist) + (b->cam.dirup * (b->vp.h /2 ))) - (rightVec * (b->vp.w / 2))

}


