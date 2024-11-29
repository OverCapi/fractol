/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/29 18:34:44 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_pixel_color(t_img img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

// area : [x_min, y_min, x_max, y_max]
void	render(t_setting setting, t_img *img, double area[4])
{
	double		x;
	double		y;
	t_complex	c;

	y = area[1];
	while (y < area[3])
	{
		x = area[0];
		while (x < area[2])
		{
			c.re = x + setting.offset_x;
			c.im = y + setting.offset_y;
			put_pixel(img, x, y, setting.fractal_fct(c, setting.zoom));
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
	setting.zoom = 500;
	setting.zoom_factor = 1.5;
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
	{
		setting.color_index = 0;
		setting.fractal_fct = mandelbrot;
	}
	else
		exit_prog(ERROR_ARG, 2, 1);
	return (setting);
}

// area : [x_min, y_min, x_max, y_max]
t_img	copy_image_offset(t_vars *vars, double offset[2])
{
	t_img		new_img;
	double		x;
	double		y;
	double		x_new;
	double		y_new;

	y = 0;
	new_img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	new_img.addr = mlx_get_data_addr(new_img.img, &new_img.bits_per_pixel, \
	&new_img.line_length, &new_img.endian);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			x_new = x + offset[0];
			y_new = y + offset[1];
			if (x_new >= 0 && x_new < WIN_WIDTH && y_new >= 0 && y_new < WIN_HEIGHT)
				put_pixel(&new_img, x_new, y_new, get_pixel_color(vars->img, x, y));
			x++;
		}
		y++;
	}
	return (new_img);
}

void	update_screen_movement(t_vars *vars)
{
	t_img	new_img;
	int		offset_x;
	int		offset_y;

	offset_x = vars->last_setting.offset_x - vars->setting.offset_x;
	offset_y = vars->last_setting.offset_y - vars->setting.offset_y;
	new_img = copy_image_offset(vars, (double[2]){offset_x, offset_y});
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = new_img;
	if (offset_x < 0)
		render(vars->setting, &vars->img, (double[4]){WIN_WIDTH + offset_x, 0, WIN_WIDTH, WIN_HEIGHT});
	else if (offset_x > 0)
		render(vars->setting, &vars->img, (double[4]){0, 0, offset_x, WIN_HEIGHT});
	if (offset_y < 0)
		render(vars->setting, &vars->img, (double[4]){0, WIN_HEIGHT + offset_y, WIN_WIDTH, WIN_HEIGHT});
	else if (offset_y > 0)
		render(vars->setting, &vars->img, (double[4]){0, 0, WIN_WIDTH, offset_y});
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, (*vars).img.img, 0, 0);
}

void	update_screen_zoom(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, \
	&vars->img.line_length, &vars->img.endian);
	render(vars->setting, &vars->img, (double[4]){0, 0, WIN_WIDTH, WIN_HEIGHT});
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	exit_fractal(t_vars *vars)
{
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	int	update;

	update = 1;
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
		update = 0;
	if (update)
		update_screen_movement(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	int	update;

	update = 1;
	if (button == SCROLL_UP)
	{
		vars->setting.zoom *= vars->setting.zoom_factor;
		vars->setting.offset_x = (vars->setting.offset_x + x - WIN_WIDTH / 2) * vars->setting.zoom_factor - x + WIN_WIDTH / 2;
		vars->setting.offset_y = (vars->setting.offset_y + y - WIN_HEIGHT / 2) * vars->setting.zoom_factor - y + WIN_HEIGHT / 2;
	}
	else if (button == SCROLL_DOWN)
	{
		vars->setting.zoom /= vars->setting.zoom_factor;
		vars->setting.offset_x = (vars->setting.offset_x + x - WIN_WIDTH / 2) / vars->setting.zoom_factor - x + WIN_WIDTH / 2;
		vars->setting.offset_y = (vars->setting.offset_y + y - WIN_HEIGHT / 2) / vars->setting.zoom_factor - y + WIN_HEIGHT / 2;
	}
	else
		update = 0;
	if (update)
		update_screen_zoom(vars);
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
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIN_WIDTH, WIN_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, \
	&vars.img.line_length, &vars.img.endian);
	render(vars.setting, &vars.img, (double[4]){0, 0, WIN_WIDTH, WIN_HEIGHT});
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
