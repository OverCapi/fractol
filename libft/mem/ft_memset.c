/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:42 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void	*s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s2 = (unsigned char *)s;
	while (i != n)
	{
		s2[i] = c;
		i++;
	}
	return (s);
}
