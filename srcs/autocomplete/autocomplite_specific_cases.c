/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_specific_cases.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:31:59 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 03:50:48 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_env_a_case(char c, char cb, int pos)
{
	if (c == '$' || (c == '{' && pos > 0 && cb == '$'))
		return (1);
	return (0);
}

int		check_oth_a_case(char c, int pos)
{
	if (c == ' ' || !pos || c == '(' || c == ';')
		return (1);
	return (0);
}

char	*dir_or_file_case(char *str, char *word)
{
	DIR	*dirp;

	if (!(dirp = opendir(str)))
	{
		free(word);
		return (ft_strdup(" "));
	}
	closedir(dirp);
	free(word);
	return (ft_strdup("/"));
}
