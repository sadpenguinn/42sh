/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:52:37 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/20 20:23:48 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONS_H
# define CONDITIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include "libft.h"

int     conditions(char **argv);
int		ft_tab_len(char **str);
int		conditions_print_error_syntax_message(char *str);
int		conditions_print_error_syntax(void);
int		b_conditions(char *str);
int		c_conditions(char *str);
int		e_conditions(char *str);
int		f_conditions(char *str);
int		g_conditions(char *str);
int		bl_conditions(char *str);
int		p_conditions(char *str);
int		r_conditions(char *str);
int		bs_conditions(char *str);
int		s_conditions(char *str);
int		u_conditions(char *str);
int		w_conditions(char *str);
int		x_conditions(char *str);
int		z_conditions(char *str);
int		equal_str_conditions(char *str1, char *str2);
int		not_equal_str_conditions(char *str1, char *str2);
int		eq_conditions(char *str1, char *str2);
int		ne_conditions(char *str1, char *str2);
int		ge_conditions(char *str1, char *str2);
int		lt_conditions(char *str1, char *str2);
int		le_conditions(char *str1, char *str2);
int		cond_switcher_for_one_other(char *flag, char *arg);
int		cond_switcher_for_one(char *flag, char *arg);
int		cond_switcher_for_two(char *flag, char *arg1, char *arg2);
void	conditions_processing(char **argv, int *res, int *i);
char    **strsplit_to_conditions(char *str);

#endif