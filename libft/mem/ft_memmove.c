/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:45:14 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/13 14:07:58 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if ((src < dest) && (src + n > dest))
	{
		while (n - 1 > 0)
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
		ptr_dest[n - 1] = ptr_src[n - 1];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
