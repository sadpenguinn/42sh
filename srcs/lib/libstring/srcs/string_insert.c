/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:06:04 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/13 20:38:22 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

int 	string_insert(t_string *string, char c, int pos)
{
	int		i;

	if (!string)
		return (STRING_ERR);
	if (pos >= string->size)
		if ((string_resize(string) == STRING_ERR))
			return (STRING_ERR);
	i = string->len - 1;
	while (i >= pos)
	{
		string->str[i + 1] = string->str[i];
		i--;
	}
	string->str[pos] = c;
	string->str[string->len + 1] = '\0';
	string->len++;
	return (STRING_OK);
}
