/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psevdo-functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:33:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/24 20:34:05 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_output_of_programm(char *str) ///////////////////////BUTCH
{
	return (ft_strdup(str));
}

void	push_to_enviroment(char *name, char *val)
{
	ssetenv(name, val);
}

char	*get_content_of_var(char *str)
{
	return (sgetenv(str));
}
