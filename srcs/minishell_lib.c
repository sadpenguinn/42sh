/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:21:15 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/22 20:22:06 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strvardup(char *str)
{
	char	*var;

	if (!ft_strcmp(str, "~") && (var = sgetenv("HOME")))
		return (ft_strdup(var));
	if (str[0] != '$')
		return (ft_strdup(str));
	if ((var = sgetenv(str + 1)))
		return (ft_strdup(var));
	return (ft_strnew(0));
}
