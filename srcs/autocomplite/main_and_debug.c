/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_and_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:07:25 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/04 20:52:42 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "autocomplite.h"

/*
** Global variables for parser
*/

void			*g_tokens = NULL;
unsigned int	g_curtok = 0;
int				g_parseerr = 0;

void	printmas(char **str)
{
	int i;

	i = 0;
	if (!str)
	{
		printf("Total NULL :(\n");
		return ;
	}
	while (str[i])
	{
		printf("str[%d] = %s\n", i, str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

int     main(int argc, char **argv, char **env)
{
	char	**res;
	t_line	*line_info;

	argc++;
	(void)argv;
	init(env);
	line_info = xmalloc(sizeof(t_line));
	line_info->buf = ft_strdup("$HO");
	res = autocomplite(line_info, 2);
	printmas(res);
	return (0);
}