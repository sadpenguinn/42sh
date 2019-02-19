/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:50:35 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/19 22:08:15 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libstring.h"

/*
** Clear memory, allocated for struct and string,
** NULL protected
*/

int		string_free(t_string *string)
{
	if (!string)
		return (STRING_ERR);
	if (string->str)
		free(string->str);
	free(string);
	return (STRING_OK);
}
