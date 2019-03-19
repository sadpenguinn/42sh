/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_files_and_dirs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:25:48 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/19 10:09:09 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int			get_autocomplite_files_dir_len(char *str)
{
	size_t	len;
	int		res_len;
	char	**res;
	char	*pattern;
	char	*real_dir;

	len = ft_strlen(str);
	pattern = atcml_get_pattern(str, len);
	real_dir = atcml_get_rel_dir(str, len);
	if (xglob(pattern, real_dir, &res, (size_t *)&res_len))
	{
		free(pattern);
		free(real_dir);
		return (0);
	}
	free(pattern);
	free(real_dir);
	glob_free(&res, res_len);
	return (res_len);
}

static char	**get_slashes_and_spases_lile_dirs(char **res, char *str)
{
	int		i;
	DIR		*dirp;
	char	*buff;
	char	*tmp[2];

	i = 0;
	(void)str;
	tmp[0] = atcml_get_rel_dir(str, ft_strlen(str));
	while (res[i])
	{
		buff = res[i];
		tmp[1] = ft_strjoin(tmp[0], res[i], 0);
		if (!(dirp = opendir(tmp[1])))
			res[i] = ft_strjoin(res[i], " ", 0);
		else
		{
			res[i] = ft_strjoin(res[i], "/", 0);
			closedir(dirp);
		}
		free(buff);
		free(tmp[1]);
		i++;
	}
	free(tmp[0]);
	return (res);
}

char		**get_autocomplite_files_dir_mas(char *str, char **res, int *c)
{
	int		i;
	size_t	len;
	char	**out_glob;
	char	*pattern;
	char	*real_dir;

	i = 0;
	len = ft_strlen(str);
	pattern = atcml_get_pattern(str, len);
	real_dir = atcml_get_rel_dir(str, len);
	if (xglob(pattern, real_dir, &out_glob, &len))
		return (res);
	out_glob = get_slashes_and_spases_lile_dirs(out_glob, str);
	out_glob = autocomplite_get_backslashing(out_glob);
	free(pattern);
	free(real_dir);
	while (out_glob[i])
	{
		res[*c] = out_glob[i];
		i++;
		(*c)++;
	}
	free(out_glob);
	res[*c] = NULL;
	return (res);
}

char		**get_only_fi_di_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len = get_autocomplite_files_dir_len(str);
	if (!len)
		return (NULL);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = get_autocomplite_files_dir_mas(str, res, &iter);
	return (res);
}
