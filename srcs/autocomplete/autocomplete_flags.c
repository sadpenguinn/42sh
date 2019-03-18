/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:12:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/18 10:50:45 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*autocomplete_get_real_programm_name(char *str)
{
	int i;
	int	pos_end;

	i = ft_strlen(str);
	while (str[i] != '-')
		i--;
	i--;
	while (str[i] == ' ')
		i--;
	pos_end = i;
	while (i && str[i] != ' ')
		i--;
	return (ft_strndup(&str[i], pos_end - i + 1));
}

int		get_autocomplite_flags_len(char *str, int *fd_to_free)
{
	char	*line;
	char	*prog;
	int		res;
	char	*tmp;

	if (!(ft_strchr(str, '-')))
		return (0);
	res = 0;
	prog = autocomplete_get_real_programm_name(str);
	printf("Program name = %s\n", prog);
	tmp = prog;
	prog = ft_strjoin(PATH_TO_FLAGS_DB, prog, 0);
	free(tmp);
	*fd_to_free = open(prog, O_RDONLY);
	if (*fd_to_free < 0)
		return (0);
	while ((get_next_line(*fd_to_free, &line)) > 0)
	{
		res++;
		printf("Line = %s\n", line);
	}
	free(prog);
	return (res + 1);
}

char	**get_autocomplite_flags_mas(char *str, char **res, int *c)
{
	int		fd;
	char	*line;
	char	*prog;
	char	*tmp;

	if (!ft_strchr(str, '-'))
		return (0);
	prog = autocomplete_get_real_programm_name(str);
	tmp = prog;
	prog = ft_strjoin(PATH_TO_FLAGS_DB, prog, 0);
	free(tmp);
	fd = open(prog, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((get_next_line(fd, &line)) > 0)
	{
		res[*c] = line;
		(*c)++;
	}
	close(fd);
	res[*c] = NULL;
	free(prog);
	return (res);
}
