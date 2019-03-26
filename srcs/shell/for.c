/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:17:36 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 19:05:12 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "readline.h"
#include "lexer.h"
#include "parser.h"
#include "execute.h"
#include "autocomplete.h"

// /*
// ** Global variables for parser
// */

// void			*g_tokens = NULL;
// unsigned int	g_curtok = 0;

static int	tab_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	for_tab_free(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

intmax_t	for_first(char *str)
{
	int		res;
	char	*res_expr;
	char	**res_split;
	char	*to_expand;

	res_split = ft_strsplit(str, ';');
	if (tab_len(res_split) != 3)
		return (for_tab_free(res_split));
	to_expand = &((res_split[0])[1]);
	to_expand = expand(to_expand);
	res_expr = expression(to_expand);
	res = ft_atoi(res_expr);
	if (res_expr)
		free(res_expr);
	if (to_expand)
		free(to_expand);
	for_tab_free(res_split);
	return (res);
}

intmax_t	for_second(char *str)
{
	int		res;
	char	*res_expr;
	char	**res_split;
	char	*to_expand;

	res_split = ft_strsplit(str, ';');
	if (tab_len(res_split) != 3)
		return (0);
	to_expand = res_split[1];
	to_expand = expand(to_expand);
	res_expr = expression(to_expand);
	res = ft_atoi(res_expr);
	if (res_expr)
		free(res_expr);
	if (to_expand)
		free(to_expand);
	for_tab_free(res_split);
	return (res);
}

intmax_t	for_last(char *str)
{
	int		res;
	char	*tmp;
	char	*res_expr;
	char	**res_split;
	char	*to_expand;

	res_split = ft_strsplit(str, ';');
	if (tab_len(res_split) != 3)
		return (0);
	tmp = ft_strndup(res_split[2], ft_strlen(res_split[2]) - 1);
	free(res_split[2]);
	res_split[3] = tmp;
	to_expand = res_split[2];
	to_expand = expand(to_expand);
	res_expr = expression(to_expand);
	res = ft_atoi(res_expr);
	if (res_expr)
		free(res_expr);
	if (to_expand)
		free(to_expand);
	for_tab_free(res_split);
	return (res);
}

// int			main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		for_first(argv[1]);
// 		for_second(argv[1]);
// 		for_first(argv[1]);
// 	}
// }