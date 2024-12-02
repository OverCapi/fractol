/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:09 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/02 17:29:18 by llemmel          ###   ########.fr       */
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

# define ERROR_MLX "mlx initialization failed\n"
# define ERROR_ARG "usage : ./fractol <fractal> <option>\n\
fractal : mandelbrot, julia, burning_ship\n\
option : mandelbrot : no option\n\
     	 julia : <real part> <imaginary part>\n\
 	 burning_ship : no option\n"

# define MAX_ITERATION 100

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

typedef struct s_vars	t_vars;

typedef struct s_setting
{
	int			(*fractal_fct)(t_complex, t_vars*);
	t_complex	c_julia;
	double		offset_x;
	double		offset_y;
	double		zoom;
	double		zoom_factor;
}	t_setting;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
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

/* UTILS */
	/* COMPLEX */
t_complex	get_cartesian_coord(t_complex c, double zoom);
t_complex	square_complex(t_complex z);
t_complex	add_complex(t_complex z1, t_complex z2);

	/* COLOR */
int			blend_color(int weight[3], double ratio);

	/* IMAGE */
t_img		copy_image_offset(t_vars *vars, double offset[2]);
void		create_image(t_vars *vars);

double		ft_atod(char *str);

/* FRACTAL -> fractal_type*/
int			mandelbrot(t_complex c, t_vars *vars);
int			julia(t_complex c, t_vars *vars);
int			burning_ship(t_complex c, t_vars *vars);

/* PARSING */
t_setting	parse_arg(int argc, char **argv);

/* MLX */
void		put_pixel(t_img *img, int x, int y, int color);
void		init(t_vars *vars);

/* UPDATE */
void		update_screen_movement(t_vars *vars);
void		update_screen_zoom(t_vars *vars);
void		render(t_vars *vars, double area[4]);

/* EVENT */
int			key_hook(int keycode, t_vars *vars);
int			mouse_hook(int button, int x, int y, t_vars *vars);

#endif