/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/30 15:35:27 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_complex c, double zoom)
{
	double		n;
	t_complex	zn;

	n = 0;
	c = get_cartesian_coord(c, zoom);
	zn = (t_complex){0, 0};
	while (n < MAX_ITERATION)
	{
		zn = add_complex(square_complex(zn), c);
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){9, 15, 8}, n / MAX_ITERATION));
}
