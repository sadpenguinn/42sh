/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:26:38 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/08 13:26:39 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

void	string_fill(t_string *str, char *buf, size_t len)
{
	str->buf = (char *)xmalloc(sizeof(char) * (len + 1));
	str->len = len;
	ft_memcpy(str->buf, buf, len);
}
