/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_get_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:11:16 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 10:12:32 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_type_fd_flags_other(t_line *line_info, int pos,
																int *pos_start)
{
	if (check_onlyfd_case(line_info, pos))
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
			'(' || (pos && line_info->buf[pos - 1] == ';')) ? pos + 1 : pos);
		return (OTHER_AUTOCOMLITE);
	}
	else
		return (ERROR_AUTOCOMLITE);
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
		else if (check_onlyfd_case(line_info, pos) ||
				check_only_flags_case(line_info->buf, pos) ||
				check_oth_a_case(line_info, pos))
			return (get_type_fd_flags_other(line_info, pos, pos_start));
		pos--;
	}
	return (ERROR_AUTOCOMLITE);
}
