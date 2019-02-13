/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:50:35 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/13 20:51:24 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

int 	string_free(t_string *string)
{
	if (!string || !string->str)
		return (STRING_ERR);
	free(string->str);
	free(string);
	return (STRING_OK);
}
