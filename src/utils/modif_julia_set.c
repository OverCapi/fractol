/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_julia_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:35:36 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/04 09:35:49 by llemmel          ###   ########.fr       */
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
