/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psevdo_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:33:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/04 17:13:40 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extention.h"

char	*get_output_of_programm(char *str) ///////////////////////BUTCH Тут должна быть функция буча, которая принимает на вход программу и подставляет её вывод, но буч не пишет её уже неделю, поэтому тут будет этот ужасный коммент, пока буч не напишет функцию
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

/*
**		state 1 = <()
**		state 2 = >()
*/
int		get_fdnumber_of_substitution(char *str, int state)
{
	// printf("command = |%s|\n", str);
	(void)str;
	state++;
	return (282);
}

char	*get_argvector_of_program(int i)
{
	return (ft_strjoin(ft_strdup("argv"), ft_itoa(i), 1));
}