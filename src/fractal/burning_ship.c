/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:41 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 14:04:13 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	burning_ship(double _Complex c, t_vars *vars)
{
	double			n;
	double _Complex	zn;
	double			real;
	double			im;

	n = 0;
	c = get_cartesian_coord(c, vars->setting.zoom);
	zn = 0 + 0 * I;
	while (n < vars->setting.accuracy)
	{
		zn = fabs(get_real(zn)) + fabs(get_im(zn))* I;
		zn = zn * zn + c; 
		real = get_real(zn);
		im = get_im(zn);
		if (real * real + im * im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){255, 10, 0}, n / vars->setting.accuracy));
}
