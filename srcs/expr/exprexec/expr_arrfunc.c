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

#include "execute.h"

intmax_t (*operators[])(intmax_t operator, t_astree *node) = {
	&op_add, /* 0 */
	&op_sub, /* 1 */
	&op_div, /* 2 */
	&op_mod, /* 3 */
	&op_mul, /* 4 */
	&op_power, /* 5 */
	&op_lsh, /* 6 */
	&op_rsh, /* 7 */
	&op_gt, /* 8 */
	&op_geq, /* 9 */
	&op_lt, /* 10 */
	&op_leq, /* 11 */
	&op_eq, /* 12 */
	&op_neq, /* 13 */
	&op_band, /* 14 */
	&op_bxor, /* 15 */
	&op_bor, /* 16 */
	&op_land, /* 17 */
	&op_lor, /* 18 */
	/* &op_cond, /1* 19 *1/ */
	/* &op_ques, /1* 20 *1/ */
	/* &op_col, /1* 21 *1/ */
};
