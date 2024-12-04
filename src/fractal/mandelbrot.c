/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 18:00:54 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_complex c, t_vars *vars)
{
	double		n;
	t_complex	zn;

	n = 0;
	c = get_cartesian_coord(c, vars->setting.zoom);
	zn = (t_complex){0, 0};
	while (n < vars->setting.accuracy)
	{
		zn = add_complex(square_complex(zn), c);
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (smooth_color(vars->setting, n, sqrt(zn.re * zn.re + zn.im * zn.im)));
	// return (blend_color((int [3]){9, 15, 8}, n / vars->setting.accuracy));
}
