/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:07:55 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 22:02:23 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	draw(t_b *b)
{
            // ft_putendlcolor("draw();", MAGENTA);
	int			x;
	int			y;
	int 		color;

	x = 0;
	color = rand() % INT_MAX;
	while (x++ < b->winx)
	{
		y = 0;
		while (y++ < b->winy)
			draw_pixelvp(b, x, y, 0xffffff);
	}
	SDL_UpdateWindowSurface(b->win);
}

int main()
{
	SDL_Event	event;
	t_b			b;
	int			fin;
	double		angle;

	fin = 0;
	angle = 10.0 * M_PI / 180.0;
	init_b(&b);
	while (!fin)
	{
		while (SDL_PollEvent(&event))
		{
			ft_putendl("camdirup = ");
			vect_print(b.cam.dirup);
			ft_putendl("camdirright = ");
			vect_print(b.cam.dirright);
			if (event.type == SDL_QUIT)
				fin = 1;
			if (event.key.keysym.sym == SDLK_DOWN)
				b.cam.dirup = rotate_xy(b.cam.dirup, -angle);
			else if (event.key.keysym.sym == SDLK_UP)
				b.cam.dirup = rotate_xy(b.cam.dirup, angle);
			else if (event.key.keysym.sym == SDLK_RIGHT)
				b.cam.dirright = rotate_xy(b.cam.dirright, angle);
			else if (event.key.keysym.sym == SDLK_LEFT)
				b.cam.dirright = rotate_xy(b.cam.dirright, -angle);
			b.cam.dir = vect_prod(b.cam.dirup, b.cam.dirright);
		}
		draw(&b);
	}
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
