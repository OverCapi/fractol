/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:15:57 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 15:04:54 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_setting(t_setting *setting)
{
	ft_bzero(setting, sizeof(t_setting));
	setting->accuracy = 100;
	setting->zoom = 500;
	setting->zoom_factor = 1.5;
}

t_setting	parse_arg(int argc, char **argv)
{
	t_setting	setting;

	init_setting(&setting);
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		setting.fractal_fct = mandelbrot;
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		setting.fractal_fct = julia;
		if (argc < 4)
		{
			setting.c_julia = (t_complex){0.285, 0.01};
			ft_printf("Invalid configuration of Julia Set, using default\n");
		}
		else
			setting.c_julia = (t_complex){ft_atod(argv[2]), ft_atod(argv[3])};
	}
	else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
	{
		setting.fractal_fct = burning_ship;
		setting.zoom = 400;
		setting.offset_y = -200;
	}
	else
		exit_error(ERROR_ARG, 1);
	return (setting);
}
