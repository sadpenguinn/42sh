#include "builtins.h"
#include "shell.h"

/*
** jobs [jobspec]
*/

int				built_jobs(char **av, char **env)
{
    size_t		len;
    size_t		i;
    pid_t		pid;

    av = NULL;
    env = NULL;
    i = 0;
    len = vector_get_len(g_jobs);
    while (i < len)
    {
    	pid = *((pid_t *)vector_get_elem(g_jobs, i));
    	ft_putstr("[");
    	ft_putnbr(i + 1);
    	ft_putendl("]");
        i++;
    }
    return (SHERR_OK);
}
