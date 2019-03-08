/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitlcead <sitlcead@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:12:03 by sitlcead          #+#    #+#             */
/*   Updated: 2019/02/20 18:55:26 by sitlcead         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include "libshell.h"

#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

static int	get_pos(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	if (s1[i] == '\0' && s2[i] != '\0')
		return (0);
	return (i);
}

static int	get_prompt(char *cwd)
{
	struct passwd	*pw;

	pw = getpwuid(getuid());
//	char *str = sgetenv("HOME", ENV_ALL);
	if (getcwd(cwd, PATH_MAX) != NULL)
		return (get_pos(cwd, pw->pw_dir));
	return (-1);
}

void		add_shell_name(void)
{
	add_shell_name_style();
	array_add(SHELL_NAME, strlen(SHELL_NAME));
}

void		print_prompt(void)
{
	char	cwd[PATH_MAX];
	int		pos;

	if (g_heredoc)
		return ;
	array_add(DEFAULT_TERM_COLORS, strlen(DEFAULT_TERM_COLORS));
	array_add(TURN_ON_CURSOR, strlen(TURN_ON_CURSOR));
	add_shell_name();
	add_prompt_style();
	array_add(" ", 1);
	pos = get_prompt(cwd);
	if (pos >= 0)
	{
		if (pos != 0)
			array_add("~", 1);
		array_add(cwd + pos, strlen(cwd + pos));
		array_add("/", 1);
	}
	array_add(COLOR_DEFAULT, strlen(COLOR_DEFAULT));
	array_add("$\n", 2);
	array_add(CURSOR_CLEAR_TO_END_SCREEN, strlen(CURSOR_CLEAR_TO_END_SCREEN));
	array_flush();
}
