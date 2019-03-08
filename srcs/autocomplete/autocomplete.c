/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 01:54:05 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char	*g_built_in_lists[] =
{
	"cd", "echo", "env", "exit", "hash", "set", "setenv", "unsetenv", NULL
};

char	*get_pattern(char *buf, int pos)
{
	char	*pattern;
	int		left_pos;

	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ' && buf[left_pos - 1] != '/')
		left_pos--;
	pattern = ft_strndup(buf + left_pos, pos - left_pos);
	pattern = ft_strjoin(pattern, "*", 1);
	return (pattern);
}

char	*get_rel_dir(char *buf, int pos)
{
	int	left_pos;

	if (pos)
		pos--;
	while (pos && buf[pos] != '/' && buf[pos - 1] != ' ')
		pos--;
	left_pos = pos;
	while (left_pos && buf[left_pos - 1] != ' ')
		left_pos--;
	if (left_pos == pos)
		return (ft_strdup("./"));
	return (ft_strndup(buf + left_pos, pos - left_pos + 1));
}

int		check_env_a_case(char c, char cb, int pos)
{
	if (c == '$' || (c == '{' && pos > 0 && cb == '$'))
		return (1);
	return (0);
}

int		check_oth_a_case(char c, int pos)
{
	if (c == ' ' || !pos || c == '(' || c == ';')
		return (1);
	return (0);
}

int		get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
{
	if (pos < 0)
		return (ERROR_AUTOCOMLITE);
	pos--;
	while (pos >= 0)
	{
		if (check_env_a_case(line_info->buf[pos], line_info->buf[pos - 1], pos))
		{
			*pos_start = pos;
			return (ENV_AUTOCOMLITE);
		}
		else if (line_info->buf[pos] == '-')
		{
			*pos_start = pos;
			return (FLAGS_AUTOCOMLITE);
		}
		else if (check_oth_a_case(line_info->buf[pos], pos))
		{
			*pos_start = ((line_info->buf[pos] == ' ' ||
							line_info->buf[pos] == '(') ? pos + 1 : pos);
			return (OTHER_AUTOCOMLITE);
		}
		pos--;
	}
	return (ERROR_AUTOCOMLITE);
}

char	*ft_strendchr(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == c)
			res = &str[i];
		i++;
	}
	return (res);
}

char	*dir_or_file_case(const char *str, const char *word)
{
	DIR	*dirp;

	if (!(dirp = opendir(str)))
	{
		free(word);
		return (ft_strdup(" "));
	}
	closedir(dirp);
	free(word);
	return (ft_strdup("/"));
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
			res[j] = ft_strndup(g_env.env[i], ft_strchr(g_env.env[i], '=')
								- g_env.env[i]);
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**tab_cat(char **to_str, char **from_str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!from_str)
		return (to_str);
	while (to_str[i])
		i++;
	while (from_str[j])
	{
		to_str[i] = from_str[j];
		i++;
		j++;
	}
	to_str[i] = NULL;
	return (to_str);
}

int		autocomplite_hash_find_len(t_hash *hash, char *str)
{
	t_hshtb	*ptr;
	size_t	size;
	size_t	i;
	int		counter;

	if (!hash || !hash->table || !str)
		return (1);
	counter = 0;
	i = 0;
	size = hash->size;
	ptr = hash->table;
	while (i < size)
	{
		if (ptr->key && !(ft_strncmp(ptr->key, str, ft_strlen(str))))
			counter++;
		ptr++;
		i++;
	}
	return (counter + 1);
}

char	**autocomplite_hash_find(t_hash *hash, char *str, char **res, int *c)
{
	t_hshtb	*ptr;
	size_t	size;
	size_t	i;

	if (!hash || !hash->table || !str)
		return (NULL);
	i = 0;
	size = hash->size;
	ptr = hash->table;
	while (i < size)
	{
		if (ptr->key && !(ft_strncmp(ptr->key, str, ft_strlen(str))))
		{
			res[*c] = ft_strdup(ptr->key);
			(*c)++;
		}
		ptr++;
		i++;
	}
	res[*c] = NULL;
	return (res);
}

int		get_autocomplite_built_in_mas_len(char *str)
{
	int i;
	int	len_word;
	int	counter;

	counter = 0;
	len_word = ft_strlen(str);
	i = 0;
	while (g_built_in_lists[i])
	{
		if (!ft_strncmp(str, g_built_in_lists[i], len_word))
			counter++;
		i++;
	}
	return (counter);
}

char	**get_autocomplite_built_in_mas(char *str, char **res, int *c)
{
	int i;
	int	len_word;

	len_word = ft_strlen(str);
	i = 0;
	while (g_built_in_lists[i])
	{
		if (!ft_strncmp(str, g_built_in_lists[i], len_word))
		{
			res[*c] = ft_strdup(g_built_in_lists[i]);
			(*c)++;
		}
		i++;
	}
	return (res);
}

int		get_autocomplite_functions_mas_len(char *str)
{
	int	counter;
	int	i;
	int	n;
	int	len;

	len = ft_strlen(str);
	n = vector_get_len(g_func);
	counter = 0;
	i = 0;
	while (i < n)
	{
		if (!ft_strncmp((((t_func *)vector_get_elem(g_func, i))->name), str,
																		len))
			counter++;
		i++;
	}
	return (counter);
}

char	**get_autocomplite_functions_mas(char *str, char **res, int *c)
{
	int	i;
	int	n;
	int	len;

	len = ft_strlen(str);
	n = vector_get_len(g_func);
	i = 0;
	while (i < n)
	{
		if (!ft_strncmp((((t_func *)vector_get_elem(g_func, i))->name), str,
																		len))
		{
			res[*c] = ft_strdup(((t_func *)vector_get_elem(g_func, i))->name);
			(*c)++;
		}
		i++;
	}
	return (res);
}

int		get_autocomplite_files_dir_len(char *str)
{
	int		len;
	int		res_len;
	char	**res;

	len = ft_strlen(str);
	if (xglob(get_pattern(str, len), get_rel_dir(str, len), &res,
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
	pattern = get_pattern(str, len);
	real_dir = get_rel_dir(str, len);
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

char	**get_mas_other_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len = autocomplite_hash_find_len(g_path, str) +
			get_autocomplite_built_in_mas_len(str) +
			get_autocomplite_functions_mas_len(str) +
			get_autocomplite_files_dir_len(str);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = autocomplite_hash_find(g_path, str, res, &iter);
	res = get_autocomplite_built_in_mas(str, res, &iter);
	res = get_autocomplite_files_dir_mas(str, res, &iter);
	res = get_autocomplite_functions_mas(str, res, &iter);
	return (res);
}

char	**get_mas_of_suggetions(char *word, int type)
{
	char	**res;

	if (type == ENV_AUTOCOMLITE)
		res = get_mas_env_autocompl(&word[1]);
	else if (type == OTHER_AUTOCOMLITE)
		res = get_mas_other_autocompile(word);
	else
		return (NULL);
	return (res);
}

char	**sugg_delete_repeats(char **str)
{
	int		i;
	char	**res;

	i = 0;
	while (!ft_strcmp(str[i], str[i + 1]))
		i++;
	if (str[i + 1])
		return (str);
	i = 0;
	res = xmalloc(sizeof(char *) * 2);
	res[0] = ft_strdup(str[0]);
	res[1] = NULL;
	while (!ft_strcmp(str[i], str[i + 1]))
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (res);
}

int		sugg_check_repeats_in_all_mass(char **str, int pos, char *c)
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

char	**sugg_free_and_set_one(char **str, int pos)
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

char	**sugg_get_common_repeat(char **str, int pos_start)
{
	int		len;
	char	tmp;

	len = 0;
	tmp = 'a';
	while (sugg_check_repeats_in_all_mass(str, pos_start + len, &tmp))
		len++;
	if (len > 0)
		str = sugg_free_and_set_one(str, len + pos_start);
	return (str);
}

char	**autocomplete(t_line *line_info, int pos)
{
	int		type;
	int		pos_start;
	char	*word_to_acmlt;
	char	**res;

	if (!(type = get_autocomplite_type(line_info, pos, &pos_start)))
		return (NULL);
	word_to_acmlt = ft_strndup(&line_info->buf[pos_start], pos - pos_start);
	res = get_mas_of_suggetions(word_to_acmlt, type);
	if (!res || !res[0])
		return (NULL);
	res = sugg_delete_repeats(res);
	res = sugg_get_common_repeat(res, ft_strlen(word_to_acmlt) -
								((word_to_acmlt[0] == '$') ? 1 : 0));
	if (res[0] && !res[1])
		res[0] = cut_begin_in_unique_suggetion(word_to_acmlt, res[0]);
	return (res);
}
