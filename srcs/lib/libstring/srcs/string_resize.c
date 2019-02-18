/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:13:57 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/14 15:48:45 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libstring.h"

/*
** Internal function for realloc string
*/

int		string_resize(t_string *string)
{
	size_t	size;
	size_t	new_size;
	char	*str;

	if (!string || !string->str)
		return (STRING_ERR);
	size = string->size;
	if (size == 0)
		size = STRING_DEFAULT;
	new_size = (size_t)(((float)size * (float)STRING_RESIZE
													/ (float)100) + size);
	if (!(str = (char *)malloc(sizeof(char) * new_size)))
		return (STRING_ERR);
	ft_strcpy(str, string->str);
	free(string->str);
	string->str = str;
	string->size = new_size;
	return (STRING_OK);
}
