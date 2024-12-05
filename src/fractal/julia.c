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

int	julia(t_complex coord, t_vars *vars)
{
	double		n;
	t_complex	zn;

	n = 0;
	zn = get_cartesian_coord(coord, vars->setting.zoom);
	while (n < vars->setting.accuracy)
	{
		zn = add_complex(square_complex(zn), vars->setting.c_julia);
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){9, 15, 8}, n / vars->setting.accuracy));
}
