/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:25:04 by capi              #+#    #+#             */
/*   Updated: 2024/12/04 18:14:45 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//weight[0] = red, weight[1] = green, weight[2] = blue
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
	color[0] = ((int)(weight[0] * inv_ratio * ratio_squared * ratio)) % 255;
	color[1] = (int)(weight[1] * inv_ratio_squared * ratio_squared * 255) % 255;
	color[2] = (int)(weight[2] * inv_ratio_squared * inv_ratio * ratio) % 255;
	return ((color[0] << 16) | (color[1] << 8) | color[2]);
}

int	linear_interpolation(int color1, int color2, double ratio)
{
	int	color[3];

	color[0] = (color1 << 16) + ratio * ((color2 << 16) - (color1 << 16));
	color[1] = (color1 << 8) + ratio * ((color2 << 8) - (color1 << 8));
	color[2] = (color1) + ratio * ((color2) - (color1));
	return ((color[0] << 16) | (color[1] << 8) | color[0]);
}

int	smooth_color(t_setting setting, double n, double z_mod)
{
	double	log_2;
	double	nu;
	int		color[2];

	if (n < setting.accuracy)
	{
		log_2 = log(2);
		nu = log((0.5 * log(z_mod)) / log_2) / log_2;
		n = n + 1 - nu;
	}
	color[0] = setting.color[(int)fmod(fmod(n, 5), 5)];
	color[1] = setting.color[(int)fmod(fmod(n, 5) + 1, 5)];
	return (linear_interpolation(color[0], color[1], fmod(n, 1)));
}
