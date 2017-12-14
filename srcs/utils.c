/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/14 15:27:14 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Return the pos of the pixel in the viewplane
*/

int		draw_pixelvp(t_b *b, int x, int y, int color)
{
	int nb;
	// 2 Tests avant d'aboutir a la formule en bas
	// viewPlaneUpLeft + rightVec * xIndent * x - upVec * yIndent * y;
	// b->cam.dirup + b->cam.dirright * b->vp.xi * x - b->cam.dirup * b->vp.yi * y;

	// On calcule l'emplacement du pixel dans le viewplane
	nb = vect_normalize(vect_add(b->cam.dirup, vect_sub(vect_multnb(&vect_multnb(&b->cam.dirright,
		b->vp.xi), x), vect_multnb(&vect_multnb(&b->cam.dirup, b->vp.yi), y))));
	//On dans l'image
	*((unsigned int *)b->img->pixels + nb) = color * 1;
}
