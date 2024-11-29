/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:09 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/29 16:10:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>

# include "../libft/libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "Fract'ol"

# define ERROR_ARG "Error\n\
usage : ./fractol <fractal> <option>\n\
fractal : mandelbrot\n\
option : mandelbrot : no option\n"

# define OFFSET_STEP 100

# define ESCAPE_KEY 65307
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define UP_KEY 65362
# define DOWN_KEY 65364

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_setting
{
	int		color_index;
	int		(*fractal_fct)(t_complex, double);
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	zoom_factor;
}	t_setting;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_setting	last_setting;
	t_setting	setting;
}	t_vars;

/* COMPLEX */
t_complex	square_complex(t_complex z);
t_complex	add_complex(t_complex z1, t_complex z2);

/* COLOR */
int			blend_color(int color1, int color2, double ratio);

/* MANDELBROT */
int			mandelbrot(t_complex c, double zoom);

#endif