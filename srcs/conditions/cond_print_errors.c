/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_print_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:43:35 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 17:53:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		conditions_print_error_syntax_message(char *str)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": invalid syntax\n", 2);
	return (0);
}

int		conditions_print_error_syntax(void)
{
	ft_putstr_fd("42sh: invalid syntax\n", 2);
	return (0);
}
