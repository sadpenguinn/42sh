/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:15:48 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/25 21:43:37 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
** Function reproduce behavior of standard strerr with 42sh error defines
*/

char	*sstrerr(int e)
{
	if (e == SHERR_ENOENT)
		return ("No such file or directory");
	if (e == SHERR_CNTFRK)
		return ("Can't fork process");
	if (e == SHERR_CMNDNTF)
		return ("Command not found");
	if (e == SHERR_INVSNTX)
		return ("Invalid syntax");
	if (e == SHERR_CNTALCTMEM)
		return ("Cannot allocate memory");
	if (e == SHERR_PERMDEN)
		return ("Permission denied");
	if (e == SHERR_NSE)
		return ("No such element");
	if (e == SHERR_CNTOPF)
		return ("Cannot open file");
	return (NULL);
}
