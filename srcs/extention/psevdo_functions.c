/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psevdo_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:33:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/25 20:11:23 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_output_of_programm(char *str)
{
	char	*tmp;
	char	*res;
	
	tmp = ft_strndup(&str[2], ft_strlen(&str[2]) - 1);
	printf("Отправляю в с_оут - |%s|\n", tmp);
	res = subtitution_output(tmp);
	printf("с_оут - |%s|\n", res);
	free(tmp);
	return (res);
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
	int tmp;

	tmp = substitution(str, state);
	// printf("sub ret = %d, state = %d\n", tmp, state);
	return (tmp);
}
