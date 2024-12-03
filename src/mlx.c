/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:05:34 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 13:11:46 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init(t_vars *vars)
{
	ft_printf("MLX initialization...\n");
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
	ft_printf("MLX initialization completed\n");
}
