/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/04 20:53:38 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplite.h"

int		get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
{
	printf("get str = |%s|\n", line_info->buf);
	if (pos < 0 || line_info->buf[pos] == ' ' || line_info->buf[pos] == ';')
		return (ERROR_AUTOCOMLITE);
	while (pos >= 0 && line_info->buf[pos] != ' ' && line_info->buf[pos] != ';')
	{
		if (line_info->buf[pos] == '$')
		{
			*pos_start = pos;
			return (ENV_AUTOCOMLITE);
		}
		else if (line_info->buf[pos] == ' ')
		{
			*pos_start = pos;
			return (OTHER_AUTOCOMLITE);
		}
		pos--;
	}
	printf("Этот тип автодополнения ещё не предусмотрен\n");
	return (ERROR_AUTOCOMLITE);
}

char	*cut_begin_in_unique_suggetion(char *str, char *word)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && word[i] && str[i] == word[i])
		i++;
	while (word[i])
	{
		str[j] = word[i];
		j++;
		i++;
	}
	return (str);
}

int		get_mas_env_autocompl_len(char *str)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (g_env.env[i])
	{
		if (!(ft_strncmp(g_env.env[i], str, ft_strlen(str))))
			counter++;
		i++;
	}
	return (counter);
}

char	**get_mas_env_autocompl(char *str)
{
	char	**res;
	int		counter;
	int		i;
	int		j;

	i = 0;
	j = 0;
	counter = get_mas_env_autocompl_len(str);
	res = xmalloc(sizeof(char **) * (counter + 1));
	while (g_env.env[i])
	{
		if (!(ft_strncmp(g_env.env[i], str, ft_strlen(str))))
		{
			res[j] = ft_strdup(g_env.env[i]);
			j++;
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**get_mas_of_suggetions(char *word, int type)
{
	char	**res;

	if (type == ENV_AUTOCOMLITE)
		res = get_mas_env_autocompl(&word[1]);
	else
	{
		printf("This type is not relized yet\n");
		return (NULL);
	}
	return (res);
}

char    **autocomplite(t_line *line_info, int pos)
{
    int		type;
	int		pos_start;
	char	*word_to_acmlt;
	char	**res;

    if (!(type = get_autocomplite_type(line_info, pos, &pos_start)))
		return (NULL);
	printf("пришёл тип %d\n", type);
	word_to_acmlt = ft_strndup(&line_info->buf[pos_start], pos - pos_start);
	res = get_mas_of_suggetions(word_to_acmlt, type);
	if (res[0] && !res[1])
		cut_begin_in_unique_suggetion(res[0], word_to_acmlt);
	return (res);
}