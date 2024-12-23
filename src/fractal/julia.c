/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:34:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 14:04:12 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(double _Complex coord, t_vars *vars)
{
	double			n;
	double _Complex	zn;
	double			real;
	double			im;

	n = 0;
	zn = get_cartesian_coord(coord, vars->setting.zoom);
	while (n < vars->setting.accuracy)
	{
		zn = zn * zn + vars->setting.c_julia;
		real = get_real(zn);
		im = get_im(zn);
		if (real * real + im * im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){9, 15, 8}, n / vars->setting.accuracy));
}
