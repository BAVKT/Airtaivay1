/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:07:55 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 15:58:54 by vmercadi         ###   ########.fr       */
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
	t_b			b;

	init_b(&b);
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
