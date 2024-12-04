/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:41 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 18:01:10 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_complex	get_coord_burn(t_complex c, double zoom)
{
	t_complex	result;

	result.re = ((c.re - (WIN_WIDTH / 2)) / zoom);
	if (c.im < WIN_HEIGHT / 2)
		result.im = -((-c.im + (WIN_HEIGHT / 2)) / zoom);
	else
		result.im = ((c.im - (WIN_HEIGHT / 2)) / zoom);
	return (result);
}

int	burning_ship(t_complex c, t_vars *vars)
{
	double		n;
	t_complex	zn;

	n = 0;
	c = get_coord_burn(c, vars->setting.zoom);
	zn = (t_complex){0, 0};
	while (n < vars->setting.accuracy)
	{
		zn = square_complex((t_complex){fabs(zn.re), fabs(zn.im)});
		zn = add_complex(zn, c);
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (smooth_color(vars->setting, n, sqrt(zn.re * zn.re + zn.im * zn.im)));
	// return (blend_color((int [3]){255, 10, 0}, n / vars->setting.accuracy));
}
