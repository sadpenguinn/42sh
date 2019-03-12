/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_specific_cases.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:31:59 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 20:37:19 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_env_a_case(char c, char cb, int pos)
{
	if (c == '$' || (c == '{' && pos > 0 && cb == '$'))
		return (1);
	return (0);
}

int		check_oth_a_case(t_line *line_info, int pos)
{
	if (pos && line_info->buf[pos - 1] == ';')
		return (1);
	if (line_info->buf[pos] == ' ' || !pos || line_info->buf[pos] == '(')
	{
		if (!pos || !pos - 1)
			return (1);
		while (pos - 1)
		{
			if (line_info->buf[pos] != ' ')
				return (0);
			pos--;
		}
	}
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
