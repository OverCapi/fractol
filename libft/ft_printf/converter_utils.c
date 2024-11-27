/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:07:42 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/01 15:14:11 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_dec_size(unsigned int nb, int sign)
{
	int	signed_nb;
	int	size;

	size = 0;
	if (sign == 1)
	{
		signed_nb = (int)nb;
		while (signed_nb != 0)
		{
			signed_nb /= 10;
			size++;
		}
	}
	else
	{
		while (nb != 0)
		{
			nb /= 10;
			size++;
		}
	}
	return (size);
}

void	ft_putunbr(unsigned int nbr)
{
	if (nbr >= 10)
		ft_putunbr(nbr / 10);
	ft_putchar_fd('0' + nbr % 10, 1);
}

int	get_hex_size(size_t nb)
{
	int	size;

	size = 0;
	while (nb > 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

void	ft_puthexa(size_t nb, int maj)
{
	char	*hex;

	if (maj == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_puthexa(nb / 16, maj);
	ft_putchar_fd(hex[nb % 16], 1);
}
