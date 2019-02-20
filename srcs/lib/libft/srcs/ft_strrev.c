/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:00:45 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/20 10:41:32 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *s)
{
	char tmp;
	char *begin;
	char *end;

	begin = s;
	end = s;
	while (*end)
		end++;
	end--;
	while (begin < end)
	{
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
	return (s);
}
