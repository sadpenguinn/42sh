/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/18 14:42:10 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*g_built_in_lists[] =
{
	"cd", "echo", "env", "exit", "hash", "set", "setenv", "unsetenv", NULL
};

char	g_path_to_database[999];

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

void	init_autocomplete(void)
{
	char	*tmp;

	getcwd(g_path_to_database, sizeof(g_path_to_database));
	tmp = ft_strjoin(g_path_to_database, PATH_TO_FLAGS_DB, 0);
	ft_strcpy(g_path_to_database, tmp);
	free(tmp);
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
	// expand_backslash_handling(&word_to_acmlt, 1);
	// printf("\n\nwts = |%s|\n\n", word_to_acmlt);
	res = get_mas_of_suggetions(word_to_acmlt, type);
	if (!res || !res[0])
	{
		free(word_to_acmlt);
		return (NULL);
	}
	res = sugg_delete_repeats(res);
	res = sugg_get_common_repeat(res, word_to_acmlt, type);
	if (res[0] && !res[1])
		res[0] = cut_begin_in_unique_suggetion(word_to_acmlt, res[0]);
	free(word_to_acmlt);
	return (res);
}
