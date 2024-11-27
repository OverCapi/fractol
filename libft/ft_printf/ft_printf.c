/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:23:40 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/04 14:25:00 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_converter(va_list ptr, char specifier)
{
	size_t	len;

	len = 0;
	if (specifier == 'c')
		return (char_converter((unsigned char)va_arg(ptr, int)));
	else if (specifier == 's')
		return (str_converter(va_arg(ptr, char *)));
	else if (specifier == 'p')
		return (ptr_converter((size_t)va_arg(ptr, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (dec_converter(va_arg(ptr, unsigned int), 1));
	else if (specifier == 'u')
		return (dec_converter(va_arg(ptr, unsigned int), 0));
	else if (specifier == 'x')
		return (hex_converter(va_arg(ptr, unsigned int), 0));
	else if (specifier == 'X')
		return (hex_converter(va_arg(ptr, unsigned int), 1));
	else if (specifier == '%')
		return (char_converter('%'));
	else
		return (-1);
	return (len);
}

static int	check_convert(va_list ptr, char specifier, size_t *i, size_t *len)
{
	if (!specifier)
		return (-1);
	else if (!ft_strchr("cspdiuxX%", specifier))
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(specifier, 1);
		*len += 2;
		*i += 1;
	}
	else
	{
		*len += ft_converter(ptr, specifier);
		*i += 1;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	ptr;

	i = 0;
	len = 0;
	va_start(ptr, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (check_convert(ptr, format[i + 1], &i, &len) != 0)
				return (-1);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
