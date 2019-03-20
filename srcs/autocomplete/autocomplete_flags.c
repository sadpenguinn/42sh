/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:12:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 13:20:34 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*cut_begin_ius_flags(char *str, char *word)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = get_autocomplite_real_flags(str, 0);
	while (str[i] && word[i] && str[i] == word[i])
		i++;
	while (word[i] && word[i] != '[' && word[i] != ' ')
	{
		word[j] = word[i];
		j++;
		i++;
	}
	word[j] = 0;
	return (word);
}

char	*autocomplete_get_real_programm_name(char *str)
{
	size_t	i;
	size_t	pr_begin;
	size_t	pr_end;

	i = 0;
	pr_end = 0;
	while (str[i] && str[i] == ' ')
		i++;
	pr_begin = i;
	while (str[i])
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			pr_end = i;
		if (str[i] == '-')
			break ;
		i++;
	}
	return (ft_strndup(&str[pr_begin], pr_end - pr_begin + 1));
}

size_t	get_autocomplite_flags_len(char *str, int *fd_to_free)
{
	char	*line;
	char	*prog;
	size_t	res;
	char	*tmp;

	if (!(ft_strchr(str, '-')))
		return (0);
	res = 0;
	prog = autocomplete_get_real_programm_name(str);
	tmp = prog;
	prog = ft_strjoin(g_path_to_database, prog, 0);
	free(tmp);
	*fd_to_free = open(prog, O_RDONLY);
	free(prog);
	if (*fd_to_free < 0)
		return (0);
	while ((get_next_line(*fd_to_free, &line)) > 0)
	{
		res++;
		free(line);
	}
	return (res + 1);
}

char	*get_autocomplite_real_flags(char *str, int strdup)
{
	char	*res;
	int		i;

	i = (int)ft_strlen(str);
	while (i >= 0 && str[i] != ' ')
		i--;
	res = &str[i + 1];
	if (strdup)
		res = ft_strdup(res);
	return (res);
}

char	**get_autocomplite_flags_mas(char *str, char **res, size_t *c)
{
	int		fd;
	char	*line;
	char	*prog;
	char	*tmp;
	char	*flag;

	prog = autocomplete_get_real_programm_name(str);
	flag = get_autocomplite_real_flags(str, 0);
	tmp = prog;
	prog = ft_strjoin(g_path_to_database, prog, 0);
	free(tmp);
	if ((fd = open(prog, O_RDONLY)) < 0)
		return (0);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!(ft_strncmp(flag, line, ft_strlen(flag))))
		{
			res[*c] = ft_strdup(line);
			(*c)++;
		}
		free(line);
	}
	close(fd);
	free(prog);
	return (autocomplete_beautifulizing_mas(res));
}
