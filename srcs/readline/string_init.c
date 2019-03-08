/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:26:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:26:50 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "shell.h"

t_string	*string_init(void)
{
	t_string	*str;

	str = (t_string *)xmalloc(sizeof(t_string));
	str->len = 0;
	str->buf = NULL;
	return (str);
}
