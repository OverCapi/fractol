/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:41:00 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_in_set(char c, char const *set)
{
	return (ft_strchr(set, c) != NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set) == 1)
		start++;
	while (end > start && is_in_set(s1[end], set) == 1)
		end--;
	if (is_in_set(s1[end], set) == 1)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
