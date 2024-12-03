/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:55:29 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 15:10:55 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_zoom(t_setting *setting, int x, int y, int button)
{
	if (button == SCROLL_UP)
	{
		setting->zoom *= setting->zoom_factor;
		setting->offset_x = (setting->offset_x + x - WIN_WIDTH / 2) \
			* setting->zoom_factor - x + WIN_WIDTH / 2;
		setting->offset_y = (setting->offset_y + y - WIN_HEIGHT / 2) \
			* setting->zoom_factor - y + WIN_HEIGHT / 2;
	}
	else if (button == SCROLL_DOWN)
	{
		setting->zoom /= setting->zoom_factor;
		setting->offset_x = (setting->offset_x + x - WIN_WIDTH / 2) \
			/ setting->zoom_factor - x + WIN_WIDTH / 2;
		setting->offset_y = (setting->offset_y + y - WIN_HEIGHT / 2) \
			/ setting->zoom_factor - y + WIN_HEIGHT / 2;
	}
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	int	need_update;

	need_update = 1;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		update_zoom(&vars->setting, x, y, button);
	else
		need_update = 0;
	if (need_update)
	{
		printf("[LOG] zoom updated\n");
		update_screen(vars);
	}
	return (0);
}
