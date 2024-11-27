/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:18 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (*s != '\0')
	{
		dest[i] = f(i, *s);
		i++;
		s++;
	}
	dest[i] = '\0';
	return (dest);
}
