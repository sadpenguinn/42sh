/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:14:01 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/02 19:20:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "vector.h"

int		main(int ac, char **av)
{
	t_lexer		*lex;

	if (ac != 2)
		return (1);
	lex = lexer(av[1]);
	vector_foreach(lex->lexems, print_token);
	return (0);
}
