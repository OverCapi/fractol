/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 14:03:51 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(double _Complex c, t_vars *vars)
{
	double			n;
	double _Complex zn;
	double			real;
	double			im;

	n = 0;
	zn = 0 + 0*I;
	c = get_cartesian_coord(c, vars->setting.zoom);
	while (n < vars->setting.accuracy)
	{
		zn = zn * zn + c;
		real = get_real(zn);
		im = get_im(zn);
		if (real * real + im * im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){9, 15, 8}, n / vars->setting.accuracy));
}
