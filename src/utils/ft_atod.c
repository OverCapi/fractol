/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:56:00 by llemmel           #+#    #+#             */
/*   Updated: 2024/12/02 17:14:50 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

 static double	get_integer_part(char *str, size_t *index)
{
	double	result;

	result = 0;
	while (str[*index] && ft_isdigit(str[*index]))
	{
		result = result * 10 + str[*index] - '0';
		*index += 1;
	}
	return (result);
}

static double	get_dec_part(char *str, size_t *index)
{
	double	result;
	double	decimal;

	result = 0;
	decimal = 10;
	while (str[*index] && ft_isdigit(str[*index]))
	{
		result += (str[*index] - '0') / decimal;
		decimal *= 10;
		*index += 1;
	}
	return (result);
}

double	ft_atod(char *str)
{
	double	result;
	double	sign;
	size_t	i;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = get_integer_part(str, &i);
	if (str[i] == '.')
		i++;
	result += get_dec_part(str, &i);
	return (result * sign);
}
