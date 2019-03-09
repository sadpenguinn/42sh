/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplite_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 02:26:35 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 06:42:08 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplete.h"

int		get_autocomplite_functions_mas_len(char *str)
{
	int		counter;
	size_t	i;
	size_t	n;
	size_t	len;

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
	size_t	i;
	size_t	n;
	size_t	len;

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
