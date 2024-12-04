/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:36:11 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 09:40:52 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	setting->c_julia = (t_complex){0.285, 0.01};
}

void	set_burning_ship(t_setting *setting, int init)
{
	if (init)
		init_setting(setting);
	setting->fractal_fct = burning_ship;
	setting->zoom = 400;
	setting->offset_y = -200;
}
