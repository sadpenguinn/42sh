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
	return (228);
}

intmax_t (*operators[])(intmax_t operator, t_astree *node) = {
/* 0 */		&op_none,
/* 1 */		&op_none,
/* 2 */		&op_none,
/* 3 */		&op_none,
/* 4 */		&op_none,
/* 5 */		&op_none,
/* 6 */		&op_none,
/* 7 */		&op_add,
/* 8 */		&op_none,
/* 9 */		&op_sub,
/* 10 */	&op_none,
/* 11 */	&op_none,
/* 12 */	&op_none,
/* 13 */	&op_none,
/* 14 */	&op_none,
/* 15 */	&op_none,
/* 16 */	&op_none,
/* 17 */	&op_none,
/* 18 */	&op_none,
/* 19 */	&op_none,
/* 20 */	&op_none,
/* 21 */	&op_none,
/* 22 */	&op_none,
/* 23 */	&op_none,
/* 24 */	&op_none,
/* 25 */	&op_none,
/* 26 */	&op_none,
/* 27 */	&op_none,
/* 28 */	&op_none,
/* 29 */	&op_none,
/* 30 */	&op_none,
/* 31 */	&op_none,
/* 32 */	&op_none,
/* 33 */	&op_none,
/* 34 */	&op_none,
/* 35 */	&op_none,
/* 36 */	&op_none,
/* 37 */	&op_none,
/* 38 */	&op_none,
/* 39 */	&op_none,
/* 40 */	&op_none,
/* 41 */	&op_none,
/* 42 */	&op_none,
/* 43 */	&op_none,

	&op_add,
	&op_sub,
	&op_div,
	&op_mod,
	&op_mul,
	&op_power,
	&op_lsh,
	&op_rsh,
	&op_gt,
	&op_geq,
	&op_lt,
	&op_leq,
	&op_eq,
	&op_neq,
	&op_band,
	&op_bxor,
	&op_bor,
	&op_land,
	&op_lor,
	/* &op_cond, /1* 19 *1/ */
	/* &op_ques, /1* 20 *1/ */
	/* &op_col, /1* 21 *1/ */
};
