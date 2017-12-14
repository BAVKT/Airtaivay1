/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:37:05 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 23:24:40 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Add two vectors
*/

t_v		vect_addnb(t_v *v, double nb)
{
	t_v		c;

	c.x = v->x + nb;
	c.y = v->y + nb;
	c.z = v->z + nb;
	return (c);
}

/*
** Subtract 2 vectors
*/

t_v		vect_subnb(t_v *v, double nb)
{
	t_v		c;

	c.x = v->x - nb;
	c.y = v->y - nb;
	c.z = v->z - nb;
	return (c);
}

/*
** Multiply 2 vectors
*/

t_v		vect_multnb(t_v *v, double nb)
{
	t_v		c;

	c.x = v->x * nb;
	c.y = v->y * nb;
	c.z = v->z * nb;
	return (c);
}