/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:04:29 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/05 19:37:32 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

char    *g_built_in_lists[] = {"cd", "echo", "env", "exit", "hash", "set",
                                "setenv", "unsetenv", NULL};

int		get_autocomplite_type(t_line *line_info, int pos, int *pos_start)
{
	// printf("get str = |%s|\n", line_info->buf);
	if (pos < 0)
		return (ERROR_AUTOCOMLITE);
	pos--;
	while (pos >= 0)
	{
		if (line_info->buf[pos] == '$' || line_info->buf[pos] == '{')
		{
			*pos_start = pos;
			return (ENV_AUTOCOMLITE);
		}
		else if (line_info->buf[pos] == '-')
		{
			*pos_start = pos;
			return (FLAGS_AUTOCOMLITE);
		}
		else if (line_info->buf[pos] == ' ' || !pos ||
				line_info->buf[pos] == '(' ||
				line_info->buf[pos] == ';')
		{
			*pos_start = ((line_info->buf[pos] == ' ' ||
							line_info->buf[pos] == '(') ? pos + 1 : pos);
			return (OTHER_AUTOCOMLITE);
		}
		pos--;
	}
	// printf("Этот тип автодополнения ещё не предусмотрен\n");
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
		word[j] = word[i];
		j++;
		i++;
	}
	word[j] = 0;
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
			res[j] = ft_strndup(g_env.env[i], ft_strchr(g_env.env[i], '=')
								- g_env.env[i]);
			j++;
		}
		i++;
	}
	res[i] = NULL;
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

char	**get_mas_other_autocompile(char *str)
{
	int		len;
	int		iter;
	char	**res;

	iter = 0;
	len =	autocomplite_hash_find_len(g_path, str) +
			get_autocomplite_built_in_mas_len(str)	+
			get_autocomplite_functions_mas_len(str);
	res = xmalloc(sizeof(char *) * (len + 1));
	res = autocomplite_hash_find(g_path, str, res, &iter);
	res = get_autocomplite_built_in_mas(str, res, &iter);
	res = get_autocomplite_functions_mas(str, res, &iter);
	return (res);
}

char	**get_mas_of_suggetions(char *word, int type)
{
	char	**res;

	if (type == ENV_AUTOCOMLITE)
		res = get_mas_env_autocompl(&word[1]);
	else if (type == OTHER_AUTOCOMLITE)
	{
		res = get_mas_other_autocompile(word);
	}
	else
	{
		// printf("This type is not relized yet\n");
		return (NULL);
	}
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



char    **autocomplete(t_line *line_info, int pos)
{
    int		type;
	int		pos_start;
	char	*word_to_acmlt;
	char	**res;

    if (!(type = get_autocomplite_type(line_info, pos, &pos_start)))
		return (NULL);
	// printf("пришёл тип %d\n", type);
	word_to_acmlt = ft_strndup(&line_info->buf[pos_start], pos - pos_start);
	printf("получается, что слово для дополнения - |%s|..\n", word_to_acmlt);
	res = get_mas_of_suggetions(word_to_acmlt, type);
	if (!res || !res[0])
		return (NULL);
	res = sugg_delete_repeats(res);
	if (res[0] && !res[1])
		cut_begin_in_unique_suggetion(word_to_acmlt, res[0]);
	return (res);
}