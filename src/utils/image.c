/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:02:27 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 16:16:27 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_pixel_color(t_img img, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (0);
	dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
	return (*(int *)dst);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

// area : [x_min, y_min, x_max, y_max]
t_img	copy_image_offset(t_vars *vars, double offset[2])
{
	t_img		new_img;
	double		x;
	double		y;
	double		x_new;
	double		y_new;

	y = -1;
	new_img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bpp, \
	&new_img.size_line, &new_img.endian);
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			x_new = x + offset[0];
			y_new = y + offset[1];
			if (x_new >= 0 && x_new < WIN_WIDTH)
				if (y_new >= 0 && y_new < WIN_HEIGHT)
					put_pixel(&new_img, x_new, y_new, \
						get_pixel_color(vars->img, x, y));
		}
	}
	return (new_img);
}

void	create_image(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!vars->img.img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit_error(ERROR_MLX, 1);
	}
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, \
	&vars->img.size_line, &vars->img.endian);
}
