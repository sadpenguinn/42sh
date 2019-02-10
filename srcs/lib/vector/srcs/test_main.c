/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:04:48 by narchiba          #+#    #+#             */
/*   Updated: 2019/01/04 16:35:31 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/ioctl.h>

int		g_term_col = 0;

void	find_term_col_ammount(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_term_col = w.ws_col;
}

int		main(void)
{
	find_term_col_ammount();
	printf("col = %zd\n", g_term_col);
	size_t	*q = queue_create(sizeof(size_t));
	queue_free((void **)&q);
	return (0);
}
