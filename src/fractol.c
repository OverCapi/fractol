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

# define MAX_ITERATION 75
# define COLOR1 0x00E63946
# define COLOR2 0x00F1FAEE
# define COLOR3 0x00A8DADC
# define COLOR4 0x00457B9D
# define COLOR5 0x001D3557

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

	shift = 16;
	color = 0;
	inverse_ratio = 1 - ratio;
	while (shift >= 0)
	{
		color_component = ((color1 >> shift) & 0xFF) * ratio;
		color_component += ((color2 >> shift) & 0xFF) * inverse_ratio;
		color |= ((int)color_component << shift);
		shift -= 8;
	}
	return (color);
}

int	get_color(double n)
{
	double ratio;

	if (n == MAX_ITERATION)
		return (COLOR5);
	ratio = n / MAX_ITERATION;
	if (ratio >= 0.95)
		return (blend_colors(COLOR4, COLOR5, (ratio - 0.95) / 0.05));
	else if (ratio >= 0.75)
		return (blend_colors(COLOR3, COLOR4, (ratio - 0.75) / 0.2));
	else if (ratio >= 0.5)
		return (blend_colors(COLOR2, COLOR3, (ratio - 0.5) / 0.25));
	else
		return (blend_colors(COLOR1, COLOR2, ratio / 0.5));
}

void	mandelbrot(double x, double y, int *color)
{
	int		n;
	double	zn_x;
	double	zn_y;
	double	temp_zn_x;

	get_cartesian_coord(&x, &y);
	zn_x = 0;
	zn_y = 0;
	n = 0;
	while (zn_x * zn_x + zn_y * zn_y < 4 && n < MAX_ITERATION)
	{
		temp_zn_x = zn_x;
		zn_x = zn_x * zn_x - zn_y * zn_y + x;
		zn_y = 2 * temp_zn_x * zn_y + y;
		n++;
	}
	*color = get_color(n);
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
			mandelbrot(x, y, &color);
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
	return (0);
}