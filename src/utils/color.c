/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:25:04 by capi              #+#    #+#             */
/*   Updated: 2024/11/28 22:27:01 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	blend_color(int color1, int color2, double ratio)
{
	int			color;
	int			color_component;
	int			shift;
	double		inverse_ratio;

	shift = 24;
	color = 0;
	inverse_ratio = 1 - ratio;
	while (shift >= 0)
	{
		color_component = ((color1 >> shift) & 0xFF) * ratio;
		color_component += ((color2 >> shift) & 0xFF) * inverse_ratio;
		color |= ((int)color_component << shift);
		shift -= 8;
	}
	return (color);
}
