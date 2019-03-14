/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psevdo_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:33:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 22:41:15 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_output_of_programm(char *str)
{
	return (ft_strdup(str));
}

void	push_to_enviroment(char *name, char *val)
{
	ssetenv(name, val, ENV_RO);
}

char	*get_content_of_var(char *str)
{
	return (sgetenv(str, ENV_ALL));
}

int		get_fdnumber_of_substitution(char *str, int state)
{
	// printf("command = |%s|, state = %d\n", str, state);
	(void)str;
	state++;
	return (282);
} 
