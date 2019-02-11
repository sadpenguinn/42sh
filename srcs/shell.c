/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 20:40:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "libhash.h"

t_hshtb			**g_env = NULL;
unsigned int	g_curtok;
void			*g_tokens;
int				g_parseerr = 0;

void	init(void)
{
	int     i;

    if (!(g_env = hash_init(INITIAL_ENV_HASH_SIZE, HSH_EQ_DJB2)))
        die();
    i = 0;
    while (environ[i])
    {
        hash_insert((void *)(environ[i]), ft_strlen(environ[i]), &g_env);
        i++;
    }
}

int     main(int ac, char **av)
{
     init();
     hash_print(g_env);
    return (EXIT_SUCCESS);
}
