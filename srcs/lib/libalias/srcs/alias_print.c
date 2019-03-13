#include "../includes/libalias.h"

/*
** Prints aliases
*/

void	alias_print_sample(char *key, char **value)
{
	int		i;

	i = 0;
	ft_putstr(key);
	ft_putchar('=');
	if (!value)
	{
		ft_putchar('\n');
		return ;
	}
	while (value[i])
	{
		ft_putstr(value[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		alias_print(t_alias *alias)
{
	t_aliastb	*ptr;
	size_t		size;
	size_t		i;

	if (!alias || !alias->table)
		return (ALIAS_ERR);
	i = 0;
	size = alias->size;
	ptr = alias->table;
	while (i < size)
	{
		if (ptr->key)
			(alias_print_sample)(ptr->key, ptr->value);
		ptr++;
		i++;
	}
	return (ALIAS_OK);
}
