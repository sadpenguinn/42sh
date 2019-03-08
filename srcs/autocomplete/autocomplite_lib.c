#include "autocomplete.h"

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

char	*atcml_get_pattern(char *buf, int pos)
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

char	*atcml_get_rel_dir(char *buf, int pos)
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