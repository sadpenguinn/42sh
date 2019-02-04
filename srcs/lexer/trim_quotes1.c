/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:51:57 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/04 19:41:46 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* state A: abc...(_|''|"") */
#define A 1
/* state B: (''|"")... */
#define B 2

int		g_i = 0;
int		g_k = 0;

void	stack_push(char *stack, char c)
{
	stack[g_i] = c;
	g_i++;
}

void	stack_move(char *stack, size_t len, char *dest)
{
	int		i;

	i = 0;
	while (i <= g_i)
		dest[g_k++] = stack[i++];
	ft_bzero(stack, len);
	g_i = 0;
}

int		is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

char	*quotes_handler(char *str, size_t len, char *stack)
{
	char	*dest;
	int		state;
	int		i;

	i = 0;
	state = A;
	dest = (char *)malloc(len + 1);
	while (i < len)
	{
		if (state == A && (str[i] != ' ' || str[i] != '\''))
			stack_push(stack, str[i]);
		else if (state == A && str[i] == ' ')
		{
			stack_push(stack, str[i]);
			stack_move(stack, len, dest);
		}
		else if (state == A && str[i] == '\'')
			state = B;
		i++;
	}
	stack_move(stack, len, dest);
	return (dest);
}

char	*trim_quotes(char *str, size_t len)
{
	char	*stack;

	stack = (char *)malloc(len);
	return (quotes_handler(str, len, stack));
}

int		main(int ac, char **av)
{
	char	*dest;

	if (ac != 2)
		return (1);
	if (!(dest = trim_quotes(av[1], 100)))
		return (1);
	ft_putendl(dest);
	return (0);
}
