/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:10:27 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/16 10:21:53 by narchiba         ###   ########.fr       */
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
	unsigned long long int	c;
	int						ret;

	set_term();
	while (c != '\n')
	{
		c = 0;
		ret = read(0, &c, 1);
		printf("\nnbr = %lld\n", c);
		printf("\nret = %d\n", ret);
	}
	unset_term();
	return (0);
}
