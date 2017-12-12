/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:44:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/10 23:22:29 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H
# include "libft.h"
# include <SDL.h>
# include <math.h>
typedef struct				s_v
{
	double					x;
	double					y;
	double					z;
}							t_v;

typedef struct				s_cam
{
	struct s_v				pos;
	struct s_v				dir;
	struct s_v				dirup;
}							t_cam;

typedef struct				s_b
{
	struct s_cam			cam;
	SDL_Window				*win;
	SDL_Renderer			*rend;
	SDL_Texture				*img;
	int						winx;
	int						winy;
}							t_b;

/*
**	Errors						| error.c
*/

void						error();
void						error_quit(int e);

/*
**	Main & loop					| main.c
*/

void						loop();

/*
** Catch the events				| event.c
*/

void						event();

#endif