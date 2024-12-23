/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:15:57 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 14:35:03 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_setting	parse_arg(int argc, char **argv)
{
	t_setting	setting;

	setting = (t_setting){0};
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		set_mandelbrot(&setting, 1);
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
	{
		set_julia(&setting, 1);
		if (argc >= 4)
			setting.c_julia = ft_atod(argv[2]) + ft_atod(argv[3]) * I;
		else
			ft_printf("Set not specified or invalid, default value used\n");
	}
	else if (ft_strncmp(argv[1], "burning_ship", ft_strlen(argv[1])) == 0)
		set_burning_ship(&setting, 1);
	else
		exit_error(ERROR_ARG, 1);
	return (setting);
}
