/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_only_exec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:45:40 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 00:17:10 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		check_only_exec_case(char *str, size_t pos)
{
	if (str[pos] == '/' && pos && str[pos - 1] == '.'
		&& (!(pos - 1) || str[pos - 2] == ' ' || str[pos - 2] == ';'))\
		return (1);
	return (0);
}

char	*get_real_file(char *el_str, char *str)
{
	char *real_dir;
	char *full_path;

	real_dir = atcml_get_rel_dir(str, ft_strlen(str));
	full_path = ft_strjoin(real_dir, el_str, 0);
	full_path[ft_strlen(full_path) - 1] = '\0';
	free(real_dir);
	return (full_path);
}

int		get_only_exec_mas_len(char **all, char *str)
{
	int			counter;
	int			i;
	char		*full_path;

	i = 0;
	counter = 0;
	while (all[i])
	{
		full_path = get_real_file(all[i], str);
		if (f_conditions(full_path) && x_conditions(full_path))
			counter++;
		i++;
		free(full_path);
	}
	return (counter);
}

char	**get_only_exec_mas_filling(char **all, char *str, char **res_mas)
{
	int			counter;
	int			i;
	int			j;
	char		*full_path;

	i = 0;
	j = 0;
	counter = 0;
	while (all[i])
	{
		full_path = get_real_file(all[i], str);
		if (f_conditions(full_path) && x_conditions(full_path))
		{
			res_mas[j] = ft_strdup(all[i]);
			j++;
		}
		free(all[i]);
		free(full_path);
		i++;
	}
	res_mas[j] = NULL;
	free(all);
	return (res_mas);
}

char	**get_only_exec_fi_mas(char *str)
{
	char	**all;
	char	**res;
	int		len;

	all = get_only_fi_di_autocompile(str);
	len = get_only_exec_mas_len(all, str);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = get_only_exec_mas_filling(all, str, res);
	return (res);
}
