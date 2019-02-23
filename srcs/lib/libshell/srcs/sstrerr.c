/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strerror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <nkertzma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:15:48 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/22 16:43:09 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	return (NULL);
}
