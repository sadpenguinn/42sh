/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:13:07 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/24 08:40:42 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "term.h"
#include <fcntl.h>
#include <string.h>

void     ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

int main(void)
{
/*	int i = 0;
	while (++i < 100)
		ft_puts("a", 0);*/
	ft_puts("\e[3A\e3D", 0);
/*	char c;
	read(0, &c, 1);
	unsigned char c = 0;
	set_term();
	read(0, &c, 1);
	while (c != '\n')
	{
		printf("%d\n", c);
		read(0, &c, 1);
	}
	unset_term();*/
	return (0);
}
