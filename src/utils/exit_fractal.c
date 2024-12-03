/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:39:27 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/03 13:39:50 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	exit_fractal(t_vars *vars)
{
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_printf("Exiting Fract'ol\n");
	exit(0);
	return (0);
}
