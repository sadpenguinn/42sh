/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:15:08 by nkertzma          #+#    #+#             */
/*   Updated: 2019/01/22 19:16:06 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <inttypes.h>

extern intmax_t (*operators[500])(intmax_t operator, t_astree *node);

intmax_t	execute(t_astree *root);
intmax_t	op_sub(intmax_t operator, t_astree *node);
intmax_t	op_add(intmax_t operator, t_astree *node);

#endif
