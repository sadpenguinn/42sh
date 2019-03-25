/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/26 00:12:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENTION_H
# define EXTENTION_H

# include <pwd.h>
# include "../srcs/lib/libshell/includes/libshell.h"
# include "shell.h"
# include "expression.h"

/*
** ${parameter:-word} 1
** ${parameter:=word} 2
** ${parameter:?word} 3
** ${parameter:+word} 4
** ${#parameter}      5
** ${parameter%}      6
** ${parameter%%}     7
** ${parameter#}      8
** ${parameter##}     9
*/

void	brackets_case_in_strsplit(char *str, int *i, char c);
void	processing_stars(char **str);
char	*get_last_n_symbols(char *str, int n, int freed);
void	push_to_enviroment(char *name, char *val);
char	*get_content_of_var(char *str);
char	*use_a_default_value(char *str);
char	*assign_a_default_value(char *str);
char	*display_error_if_null_or_unset(char *str);
char	*use_an_alternate_value(char *str);
char	*get_len_of_value(char *str);
char	*remove_smallest_suffix_pattern(char *str);
char	*remove_smallest_prefix_pattern(char *str);
char	*get_classic_var(char *str);
char	*get_output_of_programm(char *str);
char	*erase_repetitions_recursion(char *str);
char	*classic_get_env(char *str);
char	*get_content_of_expression(char *str);
char	*get_content_of_expression_helper(char **str, char **res);
int		get_len_of_name_var(char *str);
int		get_len_of_dollar(char *str);
char	*get_pahom(char *str, int *i, int *len_of_expression);
char	*remalloc_result_of_extention(char *res_to_count, char *res_to_replace,
										char *buf, int n);
char	**expand_v(char *str);
char	*expand(char *str);
char	**strsplit_for_extention(char *str);
char	*remove_smallest_suffix_pattern(char *str);
char	*remove_smallest_prefix_pattern(char *str);
void	iterator_for_expand(char *str, char *res, int *i, int *j);
void	brackets_case_in_expand_v(const char *str, int *fuck_norm, int i);
int		brackets_case_in_expand(const char *str, int *f_n, int i);
char	*pre_processing_in_expand(int *f_n, char **str, int *i, int *j);
int		fuck_you_fucking_norm(char *buf, int j);
void	frashing_values(int *fuck_norm, int *i, int *j);
char	*get_last_n_symbols(char *str, int n, int freed);
char	*get_content_of_var(char *str);
char	*pre_processing_in_expand_v(int *f_n, char **str, int *i, int *j);
void	expand_backslash_handling(char **str, int is_free);
char	*get_small_redir(char *str);
char	*get_grade_redir(char *str);
char	*extention_get_just_command(char *str);
int		check_process_substitution_expand(char *str);
int		get_fdnumber_of_substitution(char *str, int state);
char	*get_arithm_extention(char *str);
char	*ft_strjoin_helper(char *str1, char *str2, int is_free1, int is_free2);
char	*get_string_from_tab_after_xglob(char **str);
char	*get_content_of_other_ex(char *str);
char	*get_ex_tilda(char *str);
char	*get_len_of_value(char *str);
char	*use_an_alternate_value(char *str);

#endif
