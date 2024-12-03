/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:57:33 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 14:50:46 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	modif_julia_set(int keycode, int mode, t_setting *setting)
{
	if (mode == 0)
	{
		if (keycode == PLUS_KEY)
			setting->c_julia.re += JULIA_STEP;
		else if (keycode == MINUS_KEY)
			setting->c_julia.re -= JULIA_STEP;
		else
			return (0);
		ft_printf("[LOG] julia set updated\n");
		return (1);
	}
	else if (mode == 1)
	{
		if (keycode == PLUS_KEY)
			setting->c_julia.im += JULIA_STEP;
		else if (keycode == MINUS_KEY)
			setting->c_julia.im -= JULIA_STEP;
		else
			return (0);
		ft_printf("[LOG] julia set updated\n");
		return (1);
	}
	else
		return (0);
}

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
	ft_printf("[LOG] movement updated\n");
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
	else if (setting->fractal_fct == julia && update_julia_set(setting))
		return (1);
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->last_setting = vars->setting;
	update_key_history(keycode, vars);
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
		ft_printf("[LOG] accuracy updated\n");
	}
	return (0);
}
