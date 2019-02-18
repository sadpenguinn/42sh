/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony </var/mail/tony>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:36:52 by tony              #+#    #+#             */
/*   Updated: 2019/02/17 17:16:45 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UT_UTILS_H
# define UT_UTILS_H

/*
** Prototypes for internal functions
*/

void	write_result(size_t count_passed, size_t total);
void	write_prompt(int id);
int		ut_ret(int ut_errno);

#endif
