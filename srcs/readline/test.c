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
	unsigned long long int c;
	set_term();
	while (c != '\n')
	{
		c = 0;
		read(0, &c, 8);
		printf("\nnbr = %llx\n", c);
	}
	unset_term();
	return (0);
}
