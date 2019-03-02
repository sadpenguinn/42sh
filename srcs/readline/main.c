/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:11:35 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:11:35 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "readline.h"
#include "term.h"
#include "shell.h"

int		main(void)
{
	char *str;

	while ((str = readline()))
	{
/*		write(1, str, strlen(str));
		write(1, "\n", 1);*/
		free(str);
	}
	return (0);
}
