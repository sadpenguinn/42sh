/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:11:16 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 15:53:19 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char		*get_real_prog_name_files_dir(char *str, int i)
{
	while (i > 0)
	{
		if (str[i] != ' ' && str[i] != '-' && str[i - 1] == ' ')
			break ;
		i--;
	}
	return (ft_strndup(&str[i], ft_strchr(&str[i], ' ') - &str[i]));
}

static int	check_list_of_clever_autocomlete(char *str, int i)
{
	char	*prog;
	int		res;

	prog = get_real_prog_name_files_dir(str, i);
	res = ONLY_FI_DIR_AUTOCOMLITE;
	if (check_only_files_case_type(prog))
		res = ONLY_FI_AUTOCOMPLITE;
	if (check_only_dir_case_type(prog))
		res = ONLY_DIR_AUTOCOMPLETE;
	free(prog);
	return (res);
}

int			get_type_fd_flags_other(t_line *line_info, int pos,
																int *pos_start)
{
	if (check_onlyfd_case(line_info, pos))
	{
		*pos_start = pos;
		return (check_list_of_clever_autocomlete(line_info->buf, pos));
	}
	else if (check_only_flags_case(line_info->buf, pos))
	{
		*pos_start = get_position_in_flags_case(line_info->buf, pos);
		return (FLAGS_AUTOCOMLITE);
	}
	else if (check_oth_a_case(line_info, pos))
	{
		*pos_start = ((line_info->buf[pos] == ' ' || line_info->buf[pos] ==
			'(' || (pos && line_info->buf[pos - 1] == ';')) ? pos + 1 : pos);
		return (OTHER_AUTOCOMLITE);
	}
	else
		return (ERROR_AUTOCOMLITE);
}

int			get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
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
		else if (check_onlyfd_case(line_info, pos) ||
				check_only_flags_case(line_info->buf, pos) ||
				check_oth_a_case(line_info, pos))
			return (get_type_fd_flags_other(line_info, pos, pos_start));
		pos--;
	}
	return (ERROR_AUTOCOMLITE);
}
