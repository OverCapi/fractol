/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:56:05 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_s;
	size_t	i;

	i = start;
	if (s == NULL)
		return (ft_strdup(""));
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len_s && i - start < len && s[i] != '\0')
	{
		dest[i - start] = s[i];
		i++;
	}
	dest[i - start] = '\0';
	return (dest);
}
