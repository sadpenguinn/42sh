/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerewol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:04:51 by bwerewol          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int		ft_numlen(int64_t num, int base)
{
	int			len;
	uint64_t	n;

	if (base < 2)
		return (-1);
	if (!num)
		return (1);
	len = 0;
	if (num < 0)
		len++;
	n = (num < 0) ? -num : num;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
