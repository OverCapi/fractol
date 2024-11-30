/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:34:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/30 17:02:40 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_complex coord, double zoom)
{
	double		n;
	// double		re_temp;
	t_complex	zn;

	n = 0;
	zn = get_cartesian_coord(coord, zoom);
	while (n < MAX_ITERATION)
	{
		// re_temp = zn.re * zn.re - zn.im * zn.im + 0.285;
		// zn.im = 2 * zn.re * zn.im + 0.01;
		// zn.re = re_temp;
		zn = add_complex(square_complex(zn), (t_complex){0.285, 0.01});
		if (zn.re * zn.re + zn.im * zn.im > 4)
			break ;
		n++;
	}
	return (blend_color((int [3]){9, 15, 8}, (double)n / MAX_ITERATION));
}
