/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:56:16 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:15 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libstring.h"

/*
** Init string with initial size or STRING_DEFAULT define
*/

t_string	*string_init(size_t initial_size)
{
	t_string	*string;
	char		*str;

	if (initial_size == 0)
		initial_size = STRING_DEFAULT;
	if (!(string = (t_string *)malloc(sizeof(t_string))))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * initial_size)))
	{
		free(string);
		return (NULL);
	}
	str[0] = '\0';
	string->str = str;
	string->size = initial_size;
	string->len = 0;
	return (string);
}
