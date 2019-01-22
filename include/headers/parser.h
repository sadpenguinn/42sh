/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:35:21 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/08 18:15:36 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "headers/lexer.h"

typedef struct	s_astree
{
	int				type;
	char			*content;
	struct s_astree	*left;
	struct s_astree	*right;
}				t_astree;

t_token			*g_cur;

#define ERR_ALLOC 10
#include <stdio.h>
t_astree	*parse_alloc_err(int err)
{
	printf("%d\n", err);
	return (0);
}


t_astree	*parser(void);
t_astree	*simple_list1(void);
t_astree	*simple_list(void);
void		newline_list(void);
t_astree	*pipeline_command(void);
t_astree	*pipeline(void);
t_astree	*command(void);
t_astree	*simple_command(void);
t_astree	*simple_command_element(void);
t_astree	*redirection_list(void);
t_astree	*shell_command(void);

#endif
