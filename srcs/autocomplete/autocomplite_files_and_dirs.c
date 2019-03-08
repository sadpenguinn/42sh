/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_files_and_dirs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:25:48 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 02:38:24 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_autocomplite_files_dir_len(char *str)
{
	int		len;
	int		res_len;
	char	**res;

	len = ft_strlen(str);
	if (xglob(atcml_get_pattern(str, len), atcml_get_rel_dir(str, len), &res,
		(size_t *)&res_len))
		return (0);
	return (res_len);
}

char	**get_autocomplite_files_dir_mas(char *str, char **res, int *c)
{
	int		i;
	int		len;
	char	**out_glob;
	char	*pattern;
	char	*real_dir;

	i = 0;
	len = ft_strlen(str);
	pattern = atcml_get_pattern(str, len);
	real_dir = atcml_get_rel_dir(str, len);
	if (xglob(pattern, real_dir, &out_glob, (size_t *)&len))
		return (res);
	while (out_glob[i])
	{
		res[*c] = out_glob[i];
		i++;
		(*c)++;
	}
	res[*c] = NULL;
	return (res);
}