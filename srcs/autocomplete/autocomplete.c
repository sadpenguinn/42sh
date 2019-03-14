/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 23:34:22 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*g_built_in_lists[] =
{
	"cd", "echo", "env", "exit", "hash", "set", "setenv", "unsetenv", NULL
};

char	*ft_erase_spases_in_begin(char *str, int *type)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] == ' ' || str[i] == ';')
	{
		if (str[i] == ';')
			*type = OTHER_AUTOCOMLITE;
		i++;
	}
	res = xmalloc(sizeof(char) * (ft_strlen(&str[i]) + 1));
	ft_strcpy(res, &str[i]);
	free(str);
	return (res);
}

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
	word_to_acmlt = ft_erase_spases_in_begin(word_to_acmlt, &type);
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
