/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/20 16:00:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

int		main(int ac, char **av, char **env)
{
	char	*str;

	ac = 0;
	av = NULL;
	init(env);
	ssetenv("PATH", "/Users/nkertzma/Documents/42sh");
	str = sgetpath("includes");
	if (str)
		ft_putendl(str);
	else
		ft_putendl("NONE");
	destroy();
	return (EXIT_SUCCESS);
}
