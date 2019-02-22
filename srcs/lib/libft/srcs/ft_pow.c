/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:29:43 by nkertzma          #+#    #+#             */
/*   Updated: 2019/02/21 10:55:31 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_pow(int n, int pw)
{
	unsigned long	nb;

	if (n <= 0 || pw <= 0)
		return (0);
	if (pw == 1 || n == 1)
		return (n);
	nb = (unsigned long)n;
	while (--pw)
		nb *= (unsigned long)n;
	return (nb);
}
