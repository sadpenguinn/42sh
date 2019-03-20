/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_fc_case_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:29:33 by narchiba          #+#    #+#             */
/*   Updated: 2019/03/20 15:29:34 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	built_fc_case_l(char **av, int i, int *flags, void *fc_history)
{
	built_fc_write_lines(fc_history, 1, flags, av + i);
	return (1);
}
