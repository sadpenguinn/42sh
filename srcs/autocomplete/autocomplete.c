/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:44:57 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*g_built_in_lists[] =
{
	"cd", "echo", "env", "exit", "hash", "set", "setenv", "unsetenv", NULL
};

char	**autocomplete(t_line *line_info, int pos)
{
	int		type;
	int		pos_start;
	char	*word_to_acmlt;
	char	**res;

	if (!(type = get_autocomplite_type(line_info, pos, &pos_start)))
		return (NULL);
	word_to_acmlt = ft_strndup(&line_info->buf[pos_start],
								(size_t)pos - pos_start);
	res = get_mas_of_suggetions(word_to_acmlt, type);
	if (!res || !res[0])
	{
		free(word_to_acmlt);
		return (NULL);
	}
	res = sugg_delete_repeats(res);
	res = sugg_get_common_repeat(res, word_to_acmlt);
	if (res[0] && !res[1])
		res[0] = cut_begin_in_unique_suggetion(word_to_acmlt, res[0]);
	free(word_to_acmlt);
	return (res);
}
