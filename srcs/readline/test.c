/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:10:27 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/03 05:37:56 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "term.h"
#include <fcntl.h>
#include <string.h>

void	ft_puts(char *buf, int len)
{
	if (len == 0)
		len = strlen(buf);
	write(1, buf, len);
}

int		main(void)
{
//	char a = 32;
//	char b = 112;
//	char c = 123;
//	char d = 57;
//
//	int i;
//	int j;
//
//	i = a;
//	j = a;
//	i = (i << 8) + b;
//	j = (j << 8) + c;
//	if ((i & (0xFF << 8)) == (j & (0xFF << 8)))
//		printf("equal\n");
//	else
//		printf("not equal\n");

	unsigned long long int c;
	set_term();
	while (c != '\n')
	{
		c = 0;
		read(0, &c, 1);
		printf("\nnbr = %lld\n", c);
	}
	unset_term();
	return (0);
}
