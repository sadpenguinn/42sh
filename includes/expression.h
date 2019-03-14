/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expression.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:08:43 by bwerewol          #+#    #+#             */
/*   Updated: 2019/01/22 21:34:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRESSION_H
# define EXPRESSION_H

# include <stdint.h>
# include <stdio.h>
# include "shell.h"

/* typedef struct			s_astree */
/* { */
/* 	int				type; */
/* 	char			*content; */
/* 	struct s_astree	*left; */
/* 	struct s_astree	*right; */
/* }						t_astree; */

extern unsigned int		g_excurtok;
extern void				*g_extokens;
extern int				g_exprerr;

t_astree				*expr(void);
intmax_t				calc(t_astree *root);
char					*expression(char *arg);

#endif
