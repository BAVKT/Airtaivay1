/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:12:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 15:08:55 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Init the base struct
*/

void	init_b(t_b *b)
{
	b->win = NULL;
	b->winx = 1024;
	b->winy = 768;
	init_cam(&b->cam);
	init_vp(b);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b->win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b->winx, b->winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
	b->img = SDL_GetWindowSurface(b->win);
}

/*
** Init for the viewplane struct
*/

void	init_vp(t_b *b)
{
	b->vp.w = 0.35;
	b->vp.h = 0.5;
	b->vp.xi = b->vp.w / b->winx;
	b->vp.yi = b->vp.h / b->winy;
	b->vp.dist = (b->winx / 2) / tan(b->cam.angle / 2);
}

/*
** Init the cam strcut values
*/

void	init_cam(t_cam *cam)
{
	cam->angle = 60;
	cam->dir.x = 0;
	cam->dir.y = 0;
	cam->dir.z = 1;
	cam->dirup.x = 1;
	cam->dirup.y = 0;
	cam->dirup.z = 0;
	cam->dirright.x = 0;
	cam->dirright.y = 1;
	cam->dirright.z = 0;
	cam->pos = vect_prod(cam->dir, cam->dirup);
}

/*
** Set the vector's values
*/

void	init_vect(t_v *vect, int x, int y, int z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}
