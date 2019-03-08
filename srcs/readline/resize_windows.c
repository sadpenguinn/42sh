/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_windows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:23 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 14:12:23 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "readline.h"

void	get_term_params(struct winsize	*w)
{
	ioctl(STDOUT_FILENO, TIOCGWINSZ, w);
	if (w->ws_col == 0 || w->ws_row == 0)
	{
		w->ws_col = 80;
		w->ws_row = 20;
	}
}
