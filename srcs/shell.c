/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:15:05 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/11 19:38:20 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "lexer.h"
#include "libhash.h"

#define INITIAL_ENV_HASH_SIZE 100
t_hshtb     **g_env = NULL;
export char **environ;

void    die(void)
{
    write(2, "cannot allocate memory\n", 23);
    exit(EXIT_FAILURE);
}

void	init(void)
{
	int     i;

    if (!(g_env = hash_init(INITIAL_ENV_HASH_SIZE, HSH_EQ_DJB2)))
        die();
    i = 0;
    while (environ[i])
    {
    	hash_insert((void *)(environ[i]), &g_env)
        i++;
    }
}

/*void    handling_args(int ac, char **av)
{
    return ;
}*/

/*void    starting_shell(void)
{
    t_lexer     *lex;
    t_astree    *abs;
    char        *buf;

    while (1)
    {
        get_next_line(0, &buf);
        lex = lexer(buf, ft_strlen(buf));
        abs = parser(lex->lexems);
    }
}*/

int     main(int ac, char **av)
{
     init();
/*    if (ac > 1)
        handling_args(ac, av);
    else
        starting_shell();*/
    return (EXIT_SUCCESS);
}
