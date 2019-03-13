#include "../includes/libalias.h"

void	alias_free_arr(char ***arr)
{
	int		i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while ((*arr)[i])
	{
		if ((*arr)[i])
			free((*arr)[i]);
		i++;
	}
	free((*arr));
	*arr = NULL;
}

size_t	alias_len_arr(char **arr)
{
	size_t	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

char	**alias_cpy_arr(char **arr)
{
	char	**new;
	size_t	i;

	i = 0;
	if (!arr)
		return (NULL);
	new = (char **)xmalloc(sizeof(char *) * (alias_len_arr(arr) + 1));
	while (arr[i])
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	arr[i] = NULL;
	return (new);
}

char	**alias_get_arr(const char *key, t_alias *alias)
{
	t_aliastb	*table;

	table = alias_find(key, alias);
	return (table->value);
}
