/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:55:05 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/12 20:00:32 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"

int		ft_tab_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		print_error_syntax_message(char *str)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": invalid syntax\n", 2);
	return (0);
}

int		print_error_syntax(void)
{
	ft_putstr_fd("42sh: invalid syntax\n", 2);
	return (0);
}

////////////////////////// 1P COND ////////////////////////

int		b_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISBLK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free (buff);
	return (res);
}

int		c_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISCHR(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

// отсюда не проверял

int		e_conditions(char *str)
{
	if (access(str, F_OK) != -1)
		return (1);
	return (0);
}

int		f_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISREG(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		g_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_ISGID)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		bl_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISLNK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		p_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISFIFO(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		r_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IRUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		bs_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (S_ISSOCK(buff->st_mode))
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		s_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_size > 0)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		u_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_ISUID)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		w_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IWUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		x_conditions(char *str)
{
	struct stat	*buff;
	int			res;

	buff = xmalloc(sizeof(struct stat));
	res = 0;
	if (stat(str, buff) == -1)
		return (0);
	if (buff->st_mode & S_IXUSR)
		res = 1;
	else
		res = 0;
	free(buff);
	return (res);
}

int		z_conditions(char *str)
{
	if ((!str) || (!str[0]))
		return (1);
	return (0);
}

///////////////////////// END OF 2P COND ////////////////

///////////////////////// 2P COND ///////////////////////

int		equal_str_conditions(char *str1, char *str2)
{
	if (!ft_strcmp(str1, str2))
		return (1);
	return (0);
}

int		not_equal_str_conditions(char *str1, char *str2)
{
	if (ft_strcmp(str1, str2) != 0)
		return (1);
	return (0);
}

int		eq_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) == ft_atoi(str2))
		return (1);
	return (0);
}

int		ne_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) != ft_atoi(str2))
		return (1);
	return (0);
}

int		ge_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) >= ft_atoi(str2))
		return (1);
	return (0);
}

int		lt_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) < ft_atoi(str2))
		return (1);
	return (0);
}

int		le_conditions(char *str1, char *str2)
{
	if (ft_atoi(str1) <= ft_atoi(str2))
		return (1);
	return (0);
}

////////////////////////// END OF 2P COND ///////////////////


////////////////////////// SWITHERS /////////////////////////

int		cond_switcher_for_one(char *flag, char *arg)
{
	if (!flag || !arg)
		return (print_error_syntax());
	if (!(ft_strcmp(flag, "-b")))
		return (b_conditions(arg));
	if (!(ft_strcmp(flag, "-c")))
		return (c_conditions(arg));
	if (!(ft_strcmp(flag, "-e")))
		return (e_conditions(arg));
	if (!(ft_strcmp(flag, "-f")))
		return (f_conditions(arg));
	if (!(ft_strcmp(flag, "-g")))
		return (g_conditions(arg));
	if (!(ft_strcmp(flag, "-L")))
		return (bl_conditions(arg));
	if (!(ft_strcmp(flag, "-p")))
		return (p_conditions(arg));
	if (!(ft_strcmp(flag, "-r")))
		return (r_conditions(arg));
	if (!(ft_strcmp(flag, "-S")))
		return (bs_conditions(arg));
	if (!(ft_strcmp(flag, "-s")))
		return (s_conditions(arg));
	if (!(ft_strcmp(flag, "-u")))
		return (u_conditions(arg));
	if (!(ft_strcmp(flag, "-w")))
		return (w_conditions(arg));
	if (!(ft_strcmp(flag, "-x")))
		return (x_conditions(arg));
	if (!(ft_strcmp(flag, "-z")))
		return (z_conditions(arg));
	return (print_error_syntax_message(flag));
}

int		cond_switcher_for_two(char *flag, char *arg1, char *arg2)
{
	if (!flag || !arg1 || !arg2)
		return (print_error_syntax());
	if (!(ft_strcmp(flag, "=")))
		return (equal_str_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "!=")))
		return (not_equal_str_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-eq")))
		return (eq_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-ne")))
		return (ne_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-ge")))
		return (ge_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-lt")))
		return (lt_conditions(arg1, arg2));
	if (!(ft_strcmp(flag, "-le")))
		return (le_conditions(arg1, arg2));
	return (print_error_syntax_message(flag));
}

//////////////////////// END SWITCHERS ////////////////////////

int		conditions(char **argv)
{
	int	i;
	int res;
	int n;

	n = ft_tab_len(argv);
	res = 0;
	i = 0;
	while (argv[i])
	{
		if (!(ft_strcmp(argv[i], "-a")))
			return ((res * (conditions(&argv[i + 1]))) ? 1 : 0);
		else if (!(ft_strcmp(argv[i], "-o")))
			return ((conditions(&argv[i + 1])) ? 1 : res);
		else if (argv[i][0] == '-')
		{
			if (n - i < 2)
				return (print_error_syntax());
			res = cond_switcher_for_one(argv[i], argv[i + 1]);
			i += 2;
		}
		else
		{
			if (n - i < 3)
				return (print_error_syntax());
			res = cond_switcher_for_two(argv[i + 1], argv[i], argv[i + 2]);
			i += 3;
		}
	}
	return (res);
}
