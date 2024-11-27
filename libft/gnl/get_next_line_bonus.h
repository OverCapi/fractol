/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:56:44 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/23 13:35:31 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/* GET_NEXT_LINE_UTILS */
size_t	ft_strlen_gnl(const char *str, char c);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);

/* GET_NEXT_LINE */
char	*get_next_line(int fd);

#endif