/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:50:55 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/03 19:47:17 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENTION_H
# define EXTENTION_H

# include <pwd.h>
# include "libshell.h"
# include "shell.h"

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
int		get_len_of_name_var(char *str);
int		get_len_of_dollar(char *str);
char	*get_pahom(char *str, int *i, int *len_of_expression);
char	*remalloc_result_of_extention(char *res_to_count, char *res_to_replace,
										char *buf, int n);
char	**expand_v(char *str);
char	*expand(char *str);
char	**strsplit_for_extention(char *str);
int		get_fdnumber_of_substitution(char *str, int state);
char	*extention_get_just_command(char *str);

#endif
