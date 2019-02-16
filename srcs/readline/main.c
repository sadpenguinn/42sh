/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 08:39:35 by narchiba          #+#    #+#             */
/*   Updated: 2019/02/07 11:29:07 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"
#include "term.h"
#include "shell.h"

int		main(void)
{
	int ret;
	t_matrix *matrix;

	set_term();
	ret = 1;
	g_mode = READLINE;
	while (ret)
	{
		matrix = init_matrix();
		ret = readline(matrix);
	}
	unset_term();
	return (0);
}
