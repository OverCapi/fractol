/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:09 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/05 16:12:16 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <complex.h>

# include "../libft/libft.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "Fract'ol"

# define ERROR_MLX "mlx initialization failed\n"
# define ERROR_ARG "usage : ./fractol <fractal> <option>\n\
fractal : mandelbrot, julia, burning_ship\n\
option : mandelbrot : no option\n\
     	 julia : <real part> <imaginary part>\n\
 	 burning_ship : no option\n"

# define OFFSET_STEP 100
# define JULIA_STEP 0.001

# define ON_DESTROY 17

# define ESCAPE_KEY 65307
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define UP_KEY 65362
# define DOWN_KEY 65364
# define ONE_KEY 49
# define TWO_KEY 50
# define THREE_KEY 51
# define ONE_KEY_NUMPAD 65436
# define TWO_KEY_NUMPAD 65433
# define THREE_KEY_NUMPAD 65435
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define LALT_KEY 65513
# define RALT_KEY 65514
# define X_KEY 120
# define Y_KEY 121
# define R_KEY 114

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
	int				(*fractal_fct)(double _Complex, t_vars*);
	double _Complex	c_julia;
	double			accuracy;
	double			offset_x;
	double			offset_y;
	double			zoom;
	double			zoom_factor;
	int				key_pressed[3];
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
int				blend_color(int weight[3], double ratio);
int				smooth_color(t_setting setting, double n, double z_mod);
double			ft_atod(char *str);
int				exit_fractal(t_vars *vars);
int				modif_julia_set(int keycode, int mode, t_setting *setting);

/* COMPLEX */
double			get_real(double _Complex z);
double			get_im(double _Complex z);
double _Complex	get_cartesian_coord(double _Complex c, double zoom);

/* IMAGE */
void			put_pixel(t_img *img, int x, int y, int color);
t_img			copy_image_offset(t_vars *vars, double offset[2]);
void			create_image(t_vars *vars);

/* FRACTAL */
int				mandelbrot(double _Complex c, t_vars *vars);
int				julia(double _Complex c, t_vars *vars);
int				burning_ship(double _Complex c, t_vars *vars);

/* INIT */
void			init(t_vars *vars);
void			init_setting(t_setting *setting);
void			set_mandelbrot(t_setting *setting, int init);
void			set_julia(t_setting *setting, int init);
void			set_burning_ship(t_setting *setting, int init);

/* PARSING */
t_setting		parse_arg(int argc, char **argv);

/* UPDATE */
void			update_key_history(int keycode, t_vars *vars);
int				update_julia_set(t_setting *setting);
void			update_screen_movement(t_vars *vars);
void			update_screen(t_vars *vars);
void			render(t_vars *vars, double area[4]);

/* EVENT */
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);

#endif