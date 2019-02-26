/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sputcmderr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:49:33 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libshell.h"

void	sputcmderr(char *err, char *cmd, char *arg)
{
	if (err && cmd && arg)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(arg, STDERR_FILENO);
	}
}
