/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 05:52:14 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/27 15:13:11 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_overflow(long long int nb, int sign)
{
	if (sign == 1 && nb > 2147483647)
		return (-1);
	else if (sign == -1 && (nb < -2147483648 || nb >= 2147483647))
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_iswhite_space(nptr[i]) == 1 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		if (check_overflow((long long int)nb * 10 + nptr[i] - '0', sign) == -1)
			return (0);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * sign);
}
