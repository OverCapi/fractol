/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:15:57 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 09:44:31 by llemmel          ###   ########.fr       */
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

	setting = (t_setting){0};
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		set_mandelbrot(&setting, 1);
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		set_julia(&setting, 1);
		if (argc > 4)
			setting.c_julia = (t_complex){ft_atod(argv[2]), ft_atod(argv[3])};
	}
	else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
		set_burning_ship(&setting, 1);
	else
		exit_error(ERROR_ARG, 1);
	return (setting);
}
