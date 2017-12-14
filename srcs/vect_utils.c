/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:00:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 23:24:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Sort la norme du vecteur
*/

double		vect_norme(t_v *v)
{
			// ft_putendlcolor("vect_norme();", MAGENTA);
	return(sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

/*
** Normalize a vector
*/

void		vect_normalize(t_v *v)
{
			// ft_putendlcolor("vect_normalize();", MAGENTA);
	double n;

	n = vect_norme(v);
	v->x /= n;
	v->y /= n;
	v->z /= n;
}

/*
** Print the vector values
*/

void		vect_print(t_v v)
{
	printf("x = %f | y = %f | z = %f\n", v.x, v.y, v.z);
}