/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_procession.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:33:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/18 14:15:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_onlyfd_case(t_line *line_info, int pos)
{
	// printf("line = |%s|, symb = |%s|\n", line_info->buf, &(line_info->buf[pos]));
	if (pos && (pos - 1) && line_info->buf[pos] == ' ' &&
												line_info->buf[pos - 1] != '\\')
		while (pos - 1)
		{
			if (line_info->buf[pos] == ';' || line_info->buf[pos - 1] == ';')
				return (0);
			if (line_info->buf[pos - 1] != ' ' && line_info->buf[pos - 1 != '\\'])
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
	pos -= 2;
	while (str[pos] == ' ' && pos >= 0)
		pos--;
	while (str[pos] != ' ' && pos > 0)
		pos--;
	return (pos);
}

int		get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
{
	if (pos < 0)
		return (ERROR_AUTOCOMLITE);
	pos--;
	while (pos >= 0)
	{
		if (line_info->buf[pos] == '$' || (line_info->buf[pos] == '{' &&
			pos > 0 && line_info->buf[pos - 1] == '$'))
		{
			*pos_start = pos;
			return (ENV_AUTOCOMLITE);
		}
		else if (check_onlyfd_case(line_info, pos))
		{
			*pos_start = pos;
			return (ONLY_FI_DIR_AUTOCOMLITE);
		}
		else if (check_only_flags_case(line_info->buf, pos))
		{
			*pos_start = get_position_in_flags_case(line_info->buf, pos);
			return (FLAGS_AUTOCOMLITE);
		}
		else if (check_oth_a_case(line_info, pos))
		{
			*pos_start = ((line_info->buf[pos] == ' ' || line_info->buf[pos] ==
						'(' || line_info->buf[pos - 1] == ';') ? pos + 1 : pos);
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
	if (!len)
		return (NULL);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = autocomplite_hash_find(g_path, str, res, &iter);
	res = get_autocomplite_built_in_mas(str, res, &iter);
	res = get_autocomplite_files_dir_mas(str, res, &iter);
	res = get_autocomplite_functions_mas(str, res, &iter);
	return (res);
}

void	printmas_delete(char **str)
{
	int i;

	i = 0;
	if (!str)
	{
		printf("Total NULL :(\n");
		return ;
	}
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]); /////////////////////
		i++;
	}
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

char	**get_only_fi_di_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len = get_autocomplite_files_dir_len(str);
	if (!len)
		return (NULL);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = get_autocomplite_files_dir_mas(str, res, &iter);
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
