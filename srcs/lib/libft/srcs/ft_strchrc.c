/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaelor- <bbaelor-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 21:57:13 by bbaelor-          #+#    #+#             */
/*   Updated: 2019/03/14 21:57:42 by bbaelor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  count c symbols in string
*/

int		ft_strchrc(char *str, char c)
{
	int i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}
