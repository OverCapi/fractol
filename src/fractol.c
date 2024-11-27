/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:18:07 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/27 20:18:10 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	get_cartesian_coord(double *x, double *y)
{
	*x = (*x - (WIN_WIDTH / 2)) / 500;
	if (*y < WIN_HEIGHT / 2)
		*y = (WIN_HEIGHT / 2 - *y) / 500;
	else
		*y = (*y - WIN_HEIGHT / 2) / 500;
}

int	blend_colors(int color1, int color2, double ratio)
{
	int			color;
	int			color_component;
	int			shift;
	double		inverse_ratio;

	shift = 24;
	color = 0;
	inverse_ratio = 1 - ratio;
	while (shift >= 0)
	{
		color_component = ((color1 >> shift) & 0xFF) * ratio;
		color_component += ((color2 >> shift) & 0xFF) * inverse_ratio;
		color |= (color_component << shift);
		shift -= 8;
	}
	return (color);
}

int	is_in_mandelbrot(double x, double y, int *color)
{
	int		n;
	double	zn_x;
	double	zn_y;
	double	temp_zn_x;

	get_cartesian_coord(&x, &y);
	zn_x = 0;
	zn_y = 0;
	n = 0;
	while (n < MAX_ITERATION)
	{
		temp_zn_x = zn_x;
		zn_x = zn_x * zn_x - zn_y * zn_y + x;
		zn_y = 2 * temp_zn_x * zn_y + y;
		if (zn_x * zn_x + zn_y * zn_y > 4)
		{
			*color = blend_colors(COLOR1, COLOR2, (double)n / MAX_ITERATION);
			return (0);
		}
		n++;
	}
	*color = blend_colors(COLOR1, COLOR2, 1);
	return (1);
}

void	render_mandelbrot(t_img *img)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			is_in_mandelbrot(x, y, &color);
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_img	img;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	render_mandelbrot(&img);
	ft_printf("render fini\n");
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);

	mlx_loop(mlx);
	// blend_colors(0x00000000, 0xFFFFFFFF, 0.5);
	return (0);
}