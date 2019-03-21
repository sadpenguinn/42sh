/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_only_exec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 10:45:40 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/21 12:31:11 by bbaelor-         ###   ########.fr       */
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

// char	*get_real_file(char *el_str, char *str)
// {
// 	char *real_dir;
// 	char *full_path;

// 	full_path = 

// 	real_dir = atcml_get_rel_dir(str);

// }

// int		get_only_exec_mas_len(char **all, char *str)
// {
// 	struct stat	*buff;
// 	int			res;
// 	int			counter;
// 	int			i;

// 	buff = xmalloc(sizeof(struct stat));
// 	i = 0;
// 	res = 0;
// 	counter = 0;
// 	while (all[i])
// 	{
// 		atcml_get_rel_dir(str, ft_strlen(str));
// 		if (stat(str, buff) == -1)
// 		{
// 			printf("\nКакая-то ошибка, ТАК БЫТЬ НЕ ДОЛЖНО\n buff = |%s|\n", buff);
// 			return (0);
// 		}
// 		if (buff->st_mode & S_IXUSR)
// 			counter++;
// 		i++;
// 	}
// 	free(buff);
// 	return (res);
// }

char	**get_only_exec_fi_mas(char *str)
{
	// char **all;
	// char **res;

	(void)str;
	// all = get_only_fi_di_autocompile(str);
	return (NULL);
}