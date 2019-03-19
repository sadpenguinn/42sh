/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_procession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:33:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 10:14:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_onlyfd_case(t_line *line_info, int pos)
{
	if (pos && (pos - 1) && line_info->buf[pos] == ' ' &&
												line_info->buf[pos - 1] != '\\')
		while (pos - 1)
		{
			if (line_info->buf[pos] == ';' || line_info->buf[pos - 1] == ';')
				return (0);
			if (line_info->buf[pos - 1] != ' ' &&
												line_info->buf[pos - 1 != '\\'])
				return (1);
			pos--;
		}
	return (0);
}

int		check_only_flags_case(char *str, int pos)
{
	if (str[pos] == '-' && pos - 1 > 0 && (str[pos - 1] == ' '
			|| (str[pos - 1] == '-' && (pos - 2) && str[pos - 2] == ' ')))
	{
		pos -= 2;
		while (pos >= 0)
		{
			if (str[pos] != ' ')
				return (1);
			if (!pos)
				return (0);
			pos--;
		}
		return (0);
	}
	else
		return (0);
}

int		get_position_in_flags_case(char *str, int pos)
{
	while (pos >= 0)
	{
		if (str[pos] != ' ' && str[pos] != '-' && (!pos || str[pos - 1] == ' '))
			return (pos);
		pos--;
	}
	return (0);
}

char	**get_flags_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;
	int		fd_to_free;

	iter = 0;
	len = get_autocomplite_flags_len(str, &fd_to_free);
	if (!len)
		return (NULL);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = get_autocomplite_flags_mas(str, res, &iter);
	close(fd_to_free);
	return (res);
}

char	**get_mas_of_suggetions(char *word, int type)
{
	char	**res;

	if (type == ENV_AUTOCOMLITE)
		res = get_mas_env_autocompl(&word[1]);
	else if (type == ONLY_FI_DIR_AUTOCOMLITE)
		res = get_only_fi_di_autocompile(word);
	else if (type == OTHER_AUTOCOMLITE)
		res = get_mas_other_autocompile(word);
	else if (type == FLAGS_AUTOCOMLITE)
		res = get_flags_autocompile(word);
	else
		return (NULL);
	return (res);
}
