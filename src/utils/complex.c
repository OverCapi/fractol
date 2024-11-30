/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:27:15 by capi              #+#    #+#             */
/*   Updated: 2024/11/30 16:59:49 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	get_cartesian_coord(t_complex c, double zoom)
{
	t_complex	result;

	result.re = ((c.re - (WIN_WIDTH / 2)) / zoom);
	if (c.im < WIN_HEIGHT / 2)
		result.im = ((c.im + (WIN_HEIGHT / 2)) / zoom);
	else
		result.im = ((c.im - (WIN_HEIGHT / 2)) / zoom);
	return (result);
}

// z   = a + bi
// z^2 = a^2 - b^2 + 2abi
t_complex	square_complex(t_complex z)
{
	t_complex	z_2;

	z_2.re = (z.re * z.re) - (z.im * z.im);
	z_2.im = 2 * z.re * z.im;
	return (z_2);
}

t_complex	add_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.re = z1.re + z2.re;
	result.im = z1.im + z2.im;
	return (result);
}
