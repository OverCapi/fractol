/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:57:06 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/23 13:35:07 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	if (str[len] == c && c != '\0')
		return (len + 1);
	return (len);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_gnl(src, '\0');
	if (size == 0)
		return (src_len);
	if (src_len == 0)
	{
		dst[0] = '\0';
		return (src_len);
	}
	while ((i < size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen_gnl(src, '\0');
	if (size == 0)
		return (src_len);
	dst_len = ft_strlen_gnl(dst, '\0');
	if (size <= dst_len || size == 0)
		return (size + src_len);
	while ((dst_len + i < size - 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	size_t	total_len;

	if (!s1 || !s2)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	total_len = ft_strlen_gnl(s1, '\0') + ft_strlen_gnl(s2, '\n') + 1;
	dest = (char *)malloc(total_len * sizeof(char));
	if (!dest)
		return (free(s1), NULL);
	ft_strlcpy_gnl(dest, s1, total_len);
	ft_strlcat_gnl(dest, s2, total_len);
	free(s1);
	return (dest);
}
