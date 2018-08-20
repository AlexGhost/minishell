/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:13:44 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/03 15:02:36 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long size;
	long nb;

	size = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (size <= nb)
		size = size * 10;
	size = size / 10;
	while (size > 1)
	{
		ft_putchar((nb / size) + '0');
		nb = nb % size;
		size = size / 10;
	}
	ft_putchar((nb % 10) + '0');
}
