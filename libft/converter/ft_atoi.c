/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:49 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/17 05:55:55 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int		nb;
	int		is_neg;
	int		i;

	i = 0;
	nb = 0;
	is_neg = 1;
	while (ft_iswhite_space(nptr[i]) == 1 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * is_neg);
}
