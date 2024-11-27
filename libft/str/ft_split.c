/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:21:18 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	count_word(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 1;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] != c)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strcdup(char const *src, char c, size_t *len)
{
	char	*dest;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (src && src[size] != '\0' && src[size] != c)
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0' && src[i] != c)
	{
		dest[i] = src[i];
		i++;
		*len += 1;
	}
	dest[i] = '\0';
	return (dest);
}

static void	*free_split(char **strs, size_t nb_word)
{
	size_t	i;

	i = 0;
	while (i < nb_word)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (!s[i])
			break ;
		strs[word++] = ft_strcdup(s + i, c, &i);
		if (strs[word - 1] == NULL)
			return (free_split(strs, word - 1));
		if (s[i] != '\0')
			i++;
	}
	strs[word] = NULL;
	return (strs);
}
