/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:09 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/27 20:18:41 by llemmel          ###   ########.fr       */
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

# define MAX_ITERATION 200

# define COLOR1 0x00000000
# define COLOR2 0xFFFFFFFF

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

#endif