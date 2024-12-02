/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/02 12:16:36 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_setting	parse_arg(int argc, char **argv)
{
	t_setting	setting;

	(void)argc;
	ft_memset(&setting, 0, sizeof(t_setting));
	setting.zoom = 500;
	setting.zoom_factor = 1.5;
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		setting.fractal_fct = mandelbrot;
	else if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0)
		setting.fractal_fct = julia;
	else
		exit_error(ERROR_ARG, 1);
	return (setting);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc < 2)
		exit_error(ERROR_ARG, 1);
	else
		vars.setting = parse_arg(argc, argv);
	init(&vars);
	render(vars.setting, &vars.img, (double [4]){0, WIN_WIDTH, 0, WIN_HEIGHT});
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
