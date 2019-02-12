/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:05:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/12 15:48:50 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av, char **env)
{
	ac = 0;
	av = 0;
	pid_t	ppid;
	pid_t	cpid;

	char **arg;
	int		pp[2];

	arg = malloc(sizeof(char *) * 10);
	pipe(pp);
	fcntl(pp[0], F_SETFD, FD_CLOEXEC);
	fcntl(pp[1], F_SETFD, FD_CLOEXEC);

	arg[0] = "/bin/cat";
	arg[1] = "-e";
	arg[2] = 0;
	if (!(ppid = fork()))
	{
		dup2(pp[0], STDIN_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}

	arg[0] = "/bin/echo";
	arg[1] = "dap";
	arg[2] = "dap";
	arg[3] = 0;
	if (!(cpid = fork()))
	{
		dup2(pp[1], STDOUT_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}
	waitpid(cpid, 0, WUNTRACED);

	arg[0] = "/bin/echo";
	arg[1] = "chop";
	arg[2] = "chop";
	arg[3] = 0;
	if (!(cpid = fork()))
	{
		dup2(pp[1], STDOUT_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}
	close(pp[0]);
	close(pp[1]);
	waitpid(ppid, 0, WUNTRACED);

/* 	wait(0); */
	printf("OK\n");
}
