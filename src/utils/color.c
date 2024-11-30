/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:25:04 by capi              #+#    #+#             */
/*   Updated: 2024/11/30 15:31:34 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// weight[0] = red, weight[1] = green, weight[2] = blue
// good weight = {9, 15, 8}
int	blend_color(int weight[3], double ratio)
{
	int		color[3];
	double	inv_ratio;
	double	ratio_squared;
	double	inv_ratio_squared;

	inv_ratio = 1 - ratio;
	ratio_squared = ratio * ratio;
	inv_ratio_squared = inv_ratio * inv_ratio;
	ratio *= 255;
	color[0] = (int)(weight[0] * inv_ratio * ratio_squared * ratio);
	color[1] = (int)(weight[1] * inv_ratio_squared * ratio_squared * 255);
	color[2] = (int)(weight[2] * inv_ratio_squared * inv_ratio * ratio);
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}
