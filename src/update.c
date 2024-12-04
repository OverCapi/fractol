/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:01:46 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 10:48:01 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_key_history(int keycode, t_vars *vars)
{
	vars->setting.key_pressed[2] = vars->setting.key_pressed[1];
	vars->setting.key_pressed[1] = vars->setting.key_pressed[0];
	vars->setting.key_pressed[0] = keycode;
}

int	update_julia_set(t_setting *setting)
{
	int	*key_pressed;

	key_pressed = setting->key_pressed;
	if (key_pressed[2] == LALT_KEY || key_pressed[2] == RALT_KEY)
	{
		if (key_pressed[1] == X_KEY)
			return (modif_julia_set(key_pressed[0], 0, setting));
		else if (key_pressed[1] == Y_KEY)
			return (modif_julia_set(key_pressed[0], 1, setting));
	}
	return (0);
}

void	update_screen_movement(t_vars *vars)
{
	t_img	new_img;
	int		offset_x;
	int		offset_y;

	offset_x = vars->last_setting.offset_x - vars->setting.offset_x;
	offset_y = vars->last_setting.offset_y - vars->setting.offset_y;
	new_img = copy_image_offset(vars, (double [2]){offset_x, offset_y});
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = new_img;
	if (offset_x < 0)
		render(vars, (double [4]){WIN_WIDTH + offset_x, \
			WIN_WIDTH, 0, WIN_HEIGHT});
	else if (offset_x > 0)
		render(vars, (double [4]){0, offset_x, 0, WIN_HEIGHT});
	if (offset_y < 0)
		render(vars, (double [4]){0, WIN_WIDTH, WIN_HEIGHT + offset_y, \
			WIN_HEIGHT});
	else if (offset_y > 0)
		render(vars, (double [4]){0, WIN_WIDTH, 0, offset_y});
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, (*vars).img.img, 0, 0);
}

void	update_screen(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, \
	&vars->img.size_line, &vars->img.endian);
	render(vars, (double [4]){0, WIN_WIDTH, 0, WIN_HEIGHT});
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

// area : [x_min, x_max, y_min, y_max]
void	render(t_vars *vars, double area[4])
{
	double		x;
	double		y;
	t_complex	c;

	ft_printf("[LOG] rendering...\n");
	y = area[2];
	while (y < area[3])
	{
		x = area[0];
		while (x < area[1])
		{
			c.re = x + vars->setting.offset_x;
			c.im = y + vars->setting.offset_y;
			put_pixel(&vars->img, x, y, vars->setting.fractal_fct(c, vars));
			x++;
		}
		y++;
	}
	ft_printf("[LOG] render completed\n");
}
