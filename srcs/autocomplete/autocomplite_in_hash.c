/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_in_hash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:28:16 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 12:50:50 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

size_t	autocomplite_hash_find_len(t_hash *hash, char *str)
{
	t_hshtb	*ptr;
	size_t	size;
	size_t	i;
	size_t	counter;

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
	return (counter);
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
