/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/29 16:16:52 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

# define MAX_ITERATION_MANDELBROT 100

static t_complex	get_cartesian_coord(t_complex c, double zoom)
{
	t_complex	result;

	result.re = ((c.re - (WIN_WIDTH / 2)) / zoom);
	if (c.im < WIN_HEIGHT / 2)
		result.im = (WIN_HEIGHT / 2 - c.im) / zoom;
	else
		result.im = (c.im - WIN_HEIGHT / 2) / zoom;
	return (result);
}

int	mandelbrot(t_complex c, double zoom)
{
	double		n;
	t_complex	zn;

	n = 0;
	c = get_cartesian_coord(c, zoom);
	zn = (t_complex){0, 0};
	while (n < MAX_ITERATION_MANDELBROT)
	{
		zn = add_complex(square_complex(zn), c);
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (blend_color(0x00000000, 0xFFFFFFFF, n / MAX_ITERATION_MANDELBROT));
}
