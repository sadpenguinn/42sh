/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:15:41 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:15 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libstring.h"

/*
** Concatenates strings without processing \0. If "hello\0"
** and "hello\0" were passed, the result will be "hello\0hello\0".
** If push_size is 0, the entire string will be attached
*/

char	*string_push(t_string *string, char *push, size_t push_size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!string || !push)
		return (NULL);
	if (!push_size)
		push_size = ft_strlen(push);
	while (string->size <= string->len + push_size)
		if ((string_resize(string) == STRING_ERR))
			return (NULL);
	ret	= &(string->str[string->len]);
	while (i < push_size)
	{
		string->str[string->len] = push[i];
		string->len++;
		i++;
	}
	string->str[string->len] = '\0';
	string->len++;
	return (ret);
}
