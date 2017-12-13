/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/13 21:57:38 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Return the pos of the pixel
*/

// int		get_pixel(t_b *b)
// {
	// viewPlaneUpLeft + rightVec * xIndent * x - upVec * yIndent * y
	// b->cam.dirup + b->cam.dirright * b->vp.xi * x - b->cam.dirup * b->vp.yi * y;
	// vect_add(b->cam.dirup, vect_sub(vect_multnb(&vect_multnb(&b->cam.dirright,
	// 	b->vp.xi), x), vect_multnb(&vect_multnb(&b->cam.dirup, b->vp.yi), y)));
// }
