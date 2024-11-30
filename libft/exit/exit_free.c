/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:15:06 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/30 14:16:01 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// WOK
void	exit_free(char *error_msg, void *ptr, int exit_status)
{
	if (ptr)
		free(ptr);
	exit_error(error_msg, exit_status);
}
