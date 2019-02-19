/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:05:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/14 16:28:11 by bwerewol         ###   ########.fr       */
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
	pid_t	ppid[3];
	pid_t	cpid;

	char **arg;
	char	buff[100];
	int		pp[2];
	int		pp2[2];

	arg = malloc(sizeof(char *) * 10);
	pipe(pp);
	fcntl(pp[0], F_SETFD, FD_CLOEXEC);
	fcntl(pp[1], F_SETFD, FD_CLOEXEC);
	pipe(pp2);
	fcntl(pp2[0], F_SETFD, FD_CLOEXEC);
	fcntl(pp2[1], F_SETFD, FD_CLOEXEC);

	arg[0] = "/bin/cat";
	arg[1] = "text";
	arg[2] = 0;
	if (!(ppid[0] = fork()))
	{
		dup2(pp[1], STDOUT_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}

	arg[0] = "/bin/cat";
	arg[1] = "-e";
	arg[2] = 0;
	if (!(ppid[1] = fork()))
	{
		dup2(pp[0], STDIN_FILENO);
		dup2(pp2[1], STDOUT_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}

	arg[0] = "/bin/cat";
	arg[1] = "-e";
	arg[2] = 0;
	if (!(ppid[2] = fork()))
	{
		dup2(pp2[0], STDIN_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}


	/* arg[0] = "/bin/echo"; */
	/* arg[1] = "dap"; */
	/* arg[2] = "dap"; */
	/* arg[3] = 0; */
	/* if (!(cpid = fork())) */
	/* { */
	/* 	dup2(pp[1], STDOUT_FILENO); */
	/* 	execve(arg[0], arg, env); */
	/* 	printf("fail\n"); */
	/* 	exit(1); */
	/* } */
	/* waitpid(cpid, 0, WUNTRACED); */
	/* read(pp[0], buff, 2); */
	/* write(1, buff, 2); */

	/* arg[0] = "/bin/echo"; */
	/* arg[1] = "chop"; */
	/* arg[2] = "chop"; */
	/* arg[3] = 0; */
	/* if (!(cpid = fork())) */
	/* { */
	/* 	dup2(pp[1], STDOUT_FILENO); */
	/* 	execve(arg[0], arg, env); */
	/* 	printf("fail\n"); */
	/* 	exit(1); */
	/* } */
	close(pp[0]);
	close(pp[1]);
	close(pp2[0]);
	close(pp2[1]);
	waitpid(ppid[0], 0, WUNTRACED);
	waitpid(ppid[1], 0, WUNTRACED);
	waitpid(ppid[2], 0, WUNTRACED);

/* 	wait(0); */
	printf("OK\n");
}
