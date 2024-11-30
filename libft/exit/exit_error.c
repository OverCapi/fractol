/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llemmel <llemmel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:12:32 by llemmel           #+#    #+#             */
/*   Updated: 2024/11/30 14:14:50 by llemmel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// format error : Error\n{error_msg}\n
void	exit_error(char *error_msg, int exit_status)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	exit(exit_status);
}
