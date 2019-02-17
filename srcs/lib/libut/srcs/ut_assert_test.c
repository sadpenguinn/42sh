/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_assert_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony </var/mail/tony>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:40:42 by tony              #+#    #+#             */
/*   Updated: 2019/02/17 17:29:37 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libut.h"
#include "../includes/ut_utils.h"

/* #include <sys/stat.h> */
/* #include <fcntl.h> */

/* int		ut_write_to_file(char *result) */
/* { */
/* 	char	*file; */
/* 	int		fd; */
/* 	int		i; */

/* 	i = 0; */
/* 	mkdir(UT_TMP_DIR_NAME, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); */
/* 	file = ft_strjoin("tmp/test", ft_itoa(g_utcur), 2); */
/* 	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT); */
/* 	while (result[i]) */
/* 	{ */
/* 		write(fd, &result[i], 1); */
/* 		i++; */
/* 	} */
/* 	close(fd); */
/* } */

/*
** Function to be called in the user 'sample' function
*/

int		ut_assert(char *result, char *expect)
{
	ft_putstr("Result: ");
	ft_putendl(result);
	ft_putstr("Excpect: ");
	ft_putendl(expect);
	/* if (g_utinfo.wtf != UT_WRITE_TO_FILE) */
	return (ut_ret(UT_OK));
	/* return (ut_write_to_file(result)); */
}
