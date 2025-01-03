/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:34:23 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 16:12:54 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_setting(t_setting *setting)
{
	ft_bzero(setting, sizeof(t_setting));
	setting->accuracy = 50;
	setting->zoom = 500;
	setting->zoom_factor = 1.5;
}

void	set_mandelbrot(t_setting *setting, int init)
{
	if (init)
		init_setting(setting);
	setting->fractal_fct = mandelbrot;
}

void	set_julia(t_setting *setting, int init)
{
	if (init)
		init_setting(setting);
	setting->fractal_fct = julia;
	setting->c_julia = -0.8 + 0.156 * I;
}

void	set_burning_ship(t_setting *setting, int init)
{
	if (init)
		init_setting(setting);
	setting->fractal_fct = burning_ship;
	setting->zoom = 400;
	setting->offset_y = -200;
}

void	init(t_vars *vars)
{
	ft_printf("[LOG] MLX initialization...\n");
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_error(ERROR_MLX, 1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!vars->win)
	{
		free(vars->mlx);
		exit_error(ERROR_MLX, 1);
	}
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, &exit_fractal, vars);
	create_image(vars);
	ft_printf("[LOG] MLX initialization completed\n");
}
