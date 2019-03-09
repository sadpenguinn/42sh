/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_arrfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:08:37 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/23 11:17:07 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

intmax_t	op_none(intmax_t o, t_astree *n)
{
	(void)o;
	(void)n;
	return (-228);
}

intmax_t (*operators[])(intmax_t operator, t_astree *node) = {
/* 0 */		&op_none,
/* 1 */		&op_none,
/* 2 */		&op_add,
/* 3 */		&op_none,
/* 4 */		&op_none,
/* 5 */		&op_none,
/* 6 */		&op_sub,
/* 7 */		&op_none,
/* 8 */		&op_mul,
/* 9 */		&op_pow,
/* 10 */	&op_none,
/* 11 */	&op_div,
/* 12 */	&op_none,
/* 13 */	&op_mod,
/* 14 */	&op_rsh,
/* 15 */	&op_none,
/* 16 */	&op_none,
/* 17 */	&op_gt,
/* 18 */	&op_geq,
/* 19 */	&op_lsh,
/* 20 */	&op_none,
/* 21 */	&op_lt,
/* 22 */	&op_leq,
/* 23 */	&op_none,
/* 24 */	&op_neq,
/* 25 */	&op_none,
/* 26 */	&op_eq,
/* 27 */	&op_band,
/* 28 */	&op_land,
/* 29 */	&op_none,
/* 30 */	&op_bor,
/* 31 */	&op_lor,
/* 32 */	&op_none,
/* 33 */	&op_xor,
};
