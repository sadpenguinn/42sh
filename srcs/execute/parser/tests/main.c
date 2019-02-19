
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:05:52 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/13 18:58:17 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

void *potok(void *param);

int main(int ac, char **av, char **env)
{
	ac = 0;
	av = 0;
	pid_t	ppid;

	char	**arg;
	char	buff[1000];
	int		res;
	int		pin[2];
	int		pout[2];
	int		fd;
	int		fds[100];

	pthread_t	tid;

	arg = malloc(sizeof(char *) * 10);
	pipe(pout);
	fcntl(pout[0], F_SETFD, FD_CLOEXEC);
	fcntl(pout[1], F_SETFD, FD_CLOEXEC);

	fds[0] = pout[0];
	fds[1] = open("a", O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	fds[2] = open("b", O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	fds[3] = open("c", O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	fds[4] = open("d", O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0644);
	fds[5] = -1;

	arg[0] = "/bin/cat";
	arg[1] = "text";
	arg[2] = 0;

printf("BEGIN\n");
	if (!(ppid = fork()))
	{
		dup2(pout[1], STDOUT_FILENO);
		execve(arg[0], arg, env);
		printf("fail\n");
		exit(1);
	}
printf("%d\n", *fds);
	pthread_create(&tid, 0, &potok, fds);
	waitpid(ppid, 0, 0);
	close(pout[1]);
	pthread_join(tid, NULL);
	close(pout[0]);
printf("END\n");
printf("OK\n");
}

void *potok(void *param)
{
printf("IN potok\n");
	int		*fds;
	int		fd;
	int		*tmp;
	int		res;
	char	buff[1000];

	fds = (int *)param;
printf("%d\n", *fds);
	fd = *fds;
	fds++;
	tmp = fds;
	while ((res = read(fd, buff, 1000)) > 0)
	{
printf("res:%d\n", res);
		while (*fds >= 0)
			write(*fds++, buff, res);
		fds = tmp;
	}
	return (0);
}
