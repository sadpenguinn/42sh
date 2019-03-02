/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:01:59 by bwerewol          #+#    #+#             */
/*   Updated: 2019/03/01 21:27:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"
# include "vector.h"
# include "shell.h"
# include "terminals.h"
# include <stdio.h>

extern unsigned int		g_curtok;
extern void				*g_tokens;
extern int				g_parseerr;

t_astree				*inputunit(void);
t_astree				*simple_list1(void);
t_astree				*simple_list2(void);
t_astree				*simple_list3(void);
t_astree				*pipeline_command(void);
t_astree				*pipeline(void);
t_astree				*command(void);
t_astree				*simple_command(void);
t_astree				*simple_command_element(void);
t_astree				*shell_command(void);
t_astree				*for_command(void);
t_astree				*case_command(void);
t_astree				*case_clause(void);
t_astree				*case_clause_sequence(void);
t_astree				*pattern_list(void);
t_astree				*pattern(void);
t_astree				*select_command(void);
t_astree				*if_command(void);
t_astree				*elif_clause(void);
t_astree				*group_command(void);
t_astree				*subshell(void);
t_astree				*arith_command(void);
t_astree				*cond_command(void);
t_astree				*arith_for_command(void);
t_astree				*function_def(void);
t_astree				*function_body(void);
t_astree				*compound_list(void);
t_astree				*list1(void);
t_astree				*list2(void);
t_astree				*list3(void);
int						simple_list_terminator();
int						list_terminator();
void					newline_list(void);
t_astree				*word_list(void);
t_astree				*redirection_list(void);
t_astree				*redirection(void);
t_astree				*io_file(void);
t_astree				*filename(void);
t_astree				*io_here(void);
t_astree				*here_end(void);

int						check_select_word(char *str);
int						check_arith_for(char *str);
int						check_arith_word(char *str);
int						check_word_type(t_type type);
int						check_for_word(char *str);
int						check_func_name(char *str);
int						check_redir_num(char *str);
int						check_assigment_word(const char *str);
int						checktype(t_type type);
unsigned long int		savecur(unsigned int cur);
unsigned long int		freeastree(t_astree	*root);
unsigned long int		parseerror(void);

#endif
