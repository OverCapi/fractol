/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:27:15 by capi              #+#    #+#             */
/*   Updated: 2024/11/28 22:27:42 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
