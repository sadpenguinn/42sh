/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functoins_to_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:45:45 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/02/14 18:24:13 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char	*get_extension(char *str)
{
	return (ft_strdup(str));
}

int		check_bin_in_path(char *str)
{
	if (ft_strchr(str, '/'))
		return (0);
	return (1);
}

void	switcher_in_processing(t_table_exec *exec)
{
	(void)exec;
	return ;
}

void	configure_and_run_execv(char **env, char **argv,
								t_table_exec **exec)
{
	pid_t	pid;

	(void)exec;
	pid = fork();
	if (!pid)
		execve("/bin/ls", argv, env);
}
