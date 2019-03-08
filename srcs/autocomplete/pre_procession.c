/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_procession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:33:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 02:34:36 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
{
	if (pos < 0)
		return (ERROR_AUTOCOMLITE);
	pos--;
	while (pos >= 0)
	{
		if (check_env_a_case(line_info->buf[pos], line_info->buf[pos - 1], pos))
		{
			*pos_start = pos;
			return (ENV_AUTOCOMLITE);
		}
		else if (line_info->buf[pos] == '-')
		{
			*pos_start = pos;
			return (FLAGS_AUTOCOMLITE);
		}
		else if (check_oth_a_case(line_info->buf[pos], pos))
		{
			*pos_start = ((line_info->buf[pos] == ' ' ||
							line_info->buf[pos] == '(') ? pos + 1 : pos);
			return (OTHER_AUTOCOMLITE);
		}
		pos--;
	}
	return (ERROR_AUTOCOMLITE);
}

char	**get_mas_other_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len = autocomplite_hash_find_len(g_path, str) +
			get_autocomplite_built_in_mas_len(str) +
			get_autocomplite_functions_mas_len(str) +
			get_autocomplite_files_dir_len(str);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = autocomplite_hash_find(g_path, str, res, &iter);
	res = get_autocomplite_built_in_mas(str, res, &iter);
	res = get_autocomplite_files_dir_mas(str, res, &iter);
	res = get_autocomplite_functions_mas(str, res, &iter);
	return (res);
}

char	**get_mas_of_suggetions(char *word, int type)
{
	char	**res;

	if (type == ENV_AUTOCOMLITE)
		res = get_mas_env_autocompl(&word[1]);
	else if (type == OTHER_AUTOCOMLITE)
		res = get_mas_other_autocompile(word);
	else
		return (NULL);
	return (res);
}