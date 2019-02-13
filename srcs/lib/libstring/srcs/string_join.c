/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:22:27 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/13 21:37:10 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

int		string_join(t_string *string, char *join)
{
	size_t	join_size;
	size_t	i;

	i = 0;
	if (!string || !join)
		return (STRING_ERR);
	join_size = ft_strlen(join);
	while (string->size <= string->len + join_size)
		if ((string_resize(string) == STRING_ERR))
			return (STRING_ERR);
	if (string->len > 0)
		string->len--;
	while (i < join_size)
	{
		string->str[string->len] = join[i];
		string->len++;
		i++;
	}
	string->str[string->len] = '\0';
	string->len++;
	return (STRING_OK);
}
