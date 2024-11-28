/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capi <capi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/28 23:21:02 by capi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render(t_setting setting, t_img *img)
{
	double	y;
	double	x;
	int		color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = setting.fractal_fct((t_complex){x + setting.offset_x, y + setting.offset_y});
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

t_setting	parse_arg(int argc, char **argv)
{
	t_setting	setting;

	(void)argc;
	ft_memset(&setting, 0, sizeof(t_setting));
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
	{
		setting.fractal_type = 0;
		setting.color_index = 0;
		setting.fractal_fct = mandelbrot;
	}
	else
		exit_prog(ERROR_ARG, 2, 1);
	return (setting);
}

void	update_screen(t_vars *vars)
{
	render((*vars).setting, &vars->img);
	mlx_put_image_to_window(vars->mlx, vars->win, (*vars).img.img, 0, 0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	key_handled;

	key_handled = 1;
	if (keycode == ESCAPE_KEY)
		exit(0);
	else if (keycode == RIGHT_KEY)
		vars->setting.offset_x += OFFSET_STEP;
	else if (keycode == LEFT_KEY)
		vars->setting.offset_x -= OFFSET_STEP;
	else if (keycode == UP_KEY)
		vars->setting.offset_y -= OFFSET_STEP;
	else if (keycode == DOWN_KEY)
		vars->setting.offset_y += OFFSET_STEP;
	else
		key_handled = 0;
	if (key_handled)
		update_screen(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc < 2)
		exit_prog(ERROR_ARG, 2, 1);
	else
		vars.setting = parse_arg(argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	mlx_key_hook(vars.win, key_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	render(vars.setting, &vars.img);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}