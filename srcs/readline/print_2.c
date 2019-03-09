/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:01:49 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/09 11:01:51 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "libft.h"

int		print_event_message(void)
{
	array_add(SHELL_NAME, ft_strlen(SHELL_NAME));
	array_add(": ", 2);
	array_add(EVENT_MESSAGE, ft_strlen(EVENT_MESSAGE));
	array_add(": ", 2);
	array_add(g_history->event->buf, g_history->event->len);
	string_del(&g_history->event);
	array_add("\n", 1);
	array_flush();
	return (1);
}
