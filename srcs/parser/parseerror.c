/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:03:05 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

unsigned long int	parseerror(void)
{
	t_lexem	*token;

	if (g_parseerr)
		return (0LU);
	g_parseerr = 1;
	if (g_curtok >= ((size_t *)g_tokens)[2])
	{
		ft_putstr_fd("\e[0;31m42sh: parse error near `EOF'\e[0m\n",
						STDERR_FILENO);
		return (0LU);
	}
	token = ((t_lexem *)vector_get_elem(g_tokens, g_curtok));
	ft_putstr_fd("\e[0;31m42sh: parse error near `", STDERR_FILENO);
	ft_putstr_fd(token->word, STDERR_FILENO);
	ft_putstr_fd("'\e[0m\n", STDERR_FILENO);
	return (0LU);
}
