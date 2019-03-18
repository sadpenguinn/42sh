/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_procession.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:56:58 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/18 11:55:15 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	**sugg_delete_repeats(char **str)
{
	int		i;
	char	**res;

	i = 0;
	while (!ft_strcmp(str[i], str[i + 1]))
		i++;
	if (str[i + 1] || !str[1])
		return (str);
	i = 0;
	res = xmalloc(sizeof(char *) * 2);
	res[0] = ft_strdup(str[0]);
	res[1] = NULL;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (res);
}

int		sugg_check_repeats_in_all_mass(char **str, size_t pos, char *c)
{
	int		i;
	char	tmp;

	i = 1;
	tmp = str[0][pos];
	*c = tmp;
	if (!tmp)
		return (0);
	while (str[i])
	{
		if (str[i][pos] == tmp)
			i++;
		else
			return (0);
	}
	return (1);
}

char	**sugg_free_and_set_one(char **str, size_t pos)
{
	char	*key_word;
	char	**res;
	int		i;

	i = 0;
	key_word = ft_strndup(str[0], pos);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	res = xmalloc(sizeof(char *) * 2);
	res[0] = key_word;
	res[1] = NULL;
	return (res);
}

char	**sugg_get_common_repeat(char **str, char *sugg_word)
{
	size_t	len;
	char	tmp;
	size_t	pos_start;
	char	*buf;

	// printf("after  = %s\n", sugg_word);
	if ((buf = ft_strendchr(sugg_word, '-')))
		sugg_word = buf;
	else if ((buf = ft_strendchr(sugg_word, '/')))
		sugg_word = buf + 1;
	// printf("before = %s\n", sugg_word);
	pos_start = ft_strlen(sugg_word) - ((sugg_word[0] == '$') ? 1 : 0);
	len = 0;
	tmp = 'a';
	while (sugg_check_repeats_in_all_mass(str, pos_start + len, &tmp))
		len++;
	if (len > 0)
		str = sugg_free_and_set_one(str, len + pos_start);
	return (str);
}

char	*cut_begin_in_unique_suggetion(char *str, char *word)
{
	int		i;
	int		j;
	char	*buf;

	j = 0;
	i = 0;
	if (str[0] == '$')
		str = &str[1];
	buf = ft_strendchr(str, '/');
	if ((buf && !ft_strcmp(buf + 1, word)) || !ft_strcmp(str, word))
		return (dir_or_file_case(str, word));
	if (buf)
		str = buf + 1;
	while (str[i] && word[i] && str[i] == word[i])
		i++;
	while (word[i])
	{
		word[j] = word[i];
		j++;
		i++;
	}
	word[j] = 0;
	return (word);
}
