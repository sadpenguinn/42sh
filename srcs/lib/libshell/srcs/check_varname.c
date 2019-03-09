/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_of_variable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 00:50:03 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/09 16:36:39 by bwerewol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIMIT_OF_OPEN_FD 8192

int		check_ulimit_n_nbr_valid(char *str)
{
	int			i;
	long long	nbr;

	nbr = 0;
	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (!str[i] && nbr < LIMIT_OF_OPEN_FD)
		return (1);
	return (0);
}

/*
**	  |  Takes the string in format "PATH=qwer" and
**	 \|/ return "qwer" if sting is valid, else NULL
*/

char	*check_varname(char *str)
{
	int i;

	i = 0;
	if (!str || !str[0] || (str[0] <= '9' && str[0] >= '0') || str[0] == '=')
		return ((void *)0);
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' &&
			str[i] <= 'Z') || (str[i] == '_') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		i++;
	if (str[i] == '=')
		return (str + i + 1);
	return ((void *)0);
}
