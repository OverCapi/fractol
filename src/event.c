/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:55:29 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/30 14:54:54 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	exit_fractal(t_vars *vars)
{
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_printf("Exiting Fract'ol\n");
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	need_update;

	need_update = 1;
	vars->last_setting = vars->setting;
	if (keycode == ESCAPE_KEY)
		exit_fractal(vars);
	else if (keycode == RIGHT_KEY)
		vars->setting.offset_x += OFFSET_STEP;
	else if (keycode == LEFT_KEY)
		vars->setting.offset_x -= OFFSET_STEP;
	else if (keycode == UP_KEY)
		vars->setting.offset_y -= OFFSET_STEP;
	else if (keycode == DOWN_KEY)
		vars->setting.offset_y += OFFSET_STEP;
	else
		need_update = 0;
	if (need_update)
		update_screen_movement(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	int	need_update;

	need_update = 1;
	if (button == SCROLL_UP)
	{
		vars->setting.zoom *= vars->setting.zoom_factor;
		vars->setting.offset_x = (vars->setting.offset_x + x - WIN_WIDTH / 2) \
			* vars->setting.zoom_factor - x + WIN_WIDTH / 2;
		vars->setting.offset_y = (vars->setting.offset_y + y - WIN_HEIGHT / 2) \
			* vars->setting.zoom_factor - y + WIN_HEIGHT / 2;
	}
	else if (button == SCROLL_DOWN)
	{
		vars->setting.zoom /= vars->setting.zoom_factor;
		vars->setting.offset_x = (vars->setting.offset_x + x - WIN_WIDTH / 2) \
			/ vars->setting.zoom_factor - x + WIN_WIDTH / 2;
		vars->setting.offset_y = (vars->setting.offset_y + y - WIN_HEIGHT / 2) \
			/ vars->setting.zoom_factor - y + WIN_HEIGHT / 2;
	}
	else
		need_update = 0;
	if (need_update)
		update_screen_zoom(vars);
	return (0);
}
