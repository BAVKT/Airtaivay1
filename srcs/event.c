/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 23:01:49 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 23:24:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Catch and throw the events
*/

void	event()
{
	// SDL_Event	event;

}

/*
** Rotate the x and y of the vector
*/

t_v		rotate_xy(t_v v, double angle)
{
	t_v tmp;

	tmp.x = v.x * cos(angle) - v.y * sin(angle);
	tmp.y = v.x * sin(angle) + v.y * cos(angle);
	return (tmp);
}
