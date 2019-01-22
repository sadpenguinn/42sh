/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:12:59 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:44:47 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int		main(int ac, char **av)
{
	char	**matches;
	int		cnt;

	cnt = 0;
	matches = NULL;
	if (ac != 3)
		return (1);
	if (!glob(av[2], av[1], &matches, &cnt))
	{
		ft_putstr("Count matches: ");
		ft_putnbrendl(cnt);
		ft_printcharr(matches);
	}
	return (1);
}
