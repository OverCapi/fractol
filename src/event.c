/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:55:29 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 13:46:03 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	movement_key(int keycode, t_vars *vars)
{
	if (keycode == RIGHT_KEY)
		vars->setting.offset_x += OFFSET_STEP;
	else if (keycode == LEFT_KEY)
		vars->setting.offset_x -= OFFSET_STEP;
	else if (keycode == UP_KEY)
		vars->setting.offset_y -= OFFSET_STEP;
	else if (keycode == DOWN_KEY)
		vars->setting.offset_y += OFFSET_STEP;
	else
		return (0);
	return (1);
}

static int	set_burning_ship(t_setting *setting)
{
	if (setting->fractal_fct == burning_ship)
		return (0);
	init_setting(setting);
	setting->fractal_fct = burning_ship;
	setting->zoom = 400;
	setting->offset_y = -200;
	return (1);
}

static int	fractal_key(int keycode, t_setting *setting)
{
	if (keycode == ONE_KEY || keycode == ONE_KEY_NUMPAD)
	{
		if (setting->fractal_fct == mandelbrot)
			return (0);
		init_setting(setting);
		setting->fractal_fct = mandelbrot;
	}
	else if (keycode == TWO_KEY || keycode == TWO_KEY_NUMPAD)
	{
		if (setting->fractal_fct == julia)
			return (0);
		init_setting(setting);
		setting->fractal_fct = julia;
		setting->c_julia = (t_complex){0.285, 0.01};
	}
	else if (keycode == THREE_KEY || keycode == THREE_KEY_NUMPAD)
		return (set_burning_ship(setting));
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->last_setting = vars->setting;
	if (keycode == ESCAPE_KEY)
		exit_fractal(vars);
	if (movement_key(keycode, vars))
		update_screen_movement(vars);
	else if (fractal_key(keycode, &vars->setting))
		update_screen(vars);
	else if (keycode == PLUS_KEY || \
		(keycode == MINUS_KEY && vars->setting.accuracy > 50))
	{
		if (keycode == PLUS_KEY)
			vars->setting.accuracy += 50;
		else
			vars->setting.accuracy -= 50;
		update_screen(vars);
	}
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
		update_screen(vars);
	return (0);
}
