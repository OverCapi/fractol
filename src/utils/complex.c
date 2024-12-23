/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:27:15 by capi              #+#    #+#             */
/*   Updated: 2024/12/02 16:40:09 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

inline double	get_real(double _Complex z)
{
	return (*(double *)&z);
}

inline	double	get_im(double _Complex z)
{
	return (*((double *)&z + 1));
}

inline double _Complex	get_cartesian_coord(double _Complex c, double zoom)
{
	return (((get_real(c) - WIN_WIDTH / 2) / zoom) + \
			((get_im(c) - WIN_HEIGHT / 2) / zoom) * I);
}
