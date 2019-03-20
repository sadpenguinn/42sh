/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_fc_case_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:29:36 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:29:37 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "readline.h"

static char		*get_origin_string(char *file_name)
{
	char	*origin;
	size_t	len;
	int		fd;

	len = get_file_size(file_name);
	origin = (char *)xmalloc((sizeof(char) * (len + 1)));
	fd = open(file_name, O_CREAT | O_RDONLY, 0777);
	read(fd, origin, len + 1);
	close(fd);
	return (origin);
}

static int		split_string(char **first, char **second, char *str)
{
	size_t	i;
	size_t	len;

	if (str == NULL)
		return (0);
	i = 0;
	len = ft_strlen(str);
	while (i < len && str[i] != '=')
		i++;
	if (i == len)
		return (0);
	*first = (char *)xmalloc(sizeof(char) * (i + 1));
	*second = (char *)xmalloc(sizeof(char) * (len - i));
	ft_memcpy(*first, str, i);
	ft_memcpy(*second, str + i + 1, len - i - 1);
	return (1);
}

static char		*get_script(char *first, char *second, char *file_name)
{
	char	*script;
	char	*cur;
	char	*prev;
	size_t	len1;
	size_t	len2;

	script = get_origin_string(file_name);
	if (first == NULL || second == NULL)
		return (script);
	len1 = ft_strlen(first);
	len2 = ft_strlen(second);
	prev = script;
	cur = ft_strstr(prev, first);
	while (cur)
	{
		array_add(prev, cur - prev);
		array_add(second, len2);
		prev = cur + len1;
		cur = ft_strstr(prev, first);
	}
	array_add(prev, ft_strlen(script) - (prev - script));
	free(script);
	return (array_to_string());
}

static void		write_tmp_file(void *fc_history,
		int *flags, char **av, char **file_name)
{
	int	fd;

	fd = built_fc_open_tmp_file(file_name);
	built_fc_write_lines(fc_history, fd, flags, av);
	close(fd);
}

int				built_fc_case_s(char **av, int i, int *flags, void *fc_history)
{
	char	*file_name;
	char	*first;
	char	*second;
	char	*script;
	int		ret;

	first = NULL;
	second = NULL;
	ret = split_string(&first, &second, av[i]);
	write_tmp_file(fc_history, flags, av + i + ret, &file_name);
	script = get_script(first, second, file_name);
	built_fc_parse_string(script, 1);
	free(first);
	free(second);
	free(script);
	free(file_name);
	built_fc_write_history_changes();
	return (1);
}
