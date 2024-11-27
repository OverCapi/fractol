/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:45:11 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/01 15:14:13 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_converter(unsigned char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	str_converter(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	dec_converter(unsigned int nb, int sign)
{
	int	size;

	if (sign == 1)
	{
		size = get_dec_size((int)nb, 1);
		if ((int)nb <= 0)
			size++;
		ft_putnbr_fd(nb, 1);
	}
	else
	{
		size = get_dec_size(nb, 0);
		if (nb == 0)
			size++;
		ft_putunbr(nb);
	}
	return (size);
}

int	ptr_converter(size_t addr)
{
	int	size;

	if (addr != 0)
	{
		size = get_hex_size(addr);
		write(1, "0x", 2);
		ft_puthexa(addr, 0);
		return (size + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}

int	hex_converter(unsigned int nb, int maj)
{
	int	size;

	size = get_hex_size((size_t)nb);
	if (nb == 0)
		size++;
	ft_puthexa((size_t)nb, maj);
	return (size);
}
