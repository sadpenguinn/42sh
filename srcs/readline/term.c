/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:32 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/26 17:06:15 by narchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>

static struct termios	g_old;

void	set_term(void)
{
	struct termios	new;

	tcgetattr(0, &g_old);
	new = g_old;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VEOF] = 17;
	new.c_cc[VLNEXT] = 26;
	new.c_cc[VEOF] = 4;
	new.c_cc[VREPRINT] = 22;
	new.c_cc[VQUIT] = 34;
	tcsetattr(0, TCSANOW, &new);
}

void	unset_term(void)
{
	tcsetattr(0, TCSANOW, &g_old);
}
