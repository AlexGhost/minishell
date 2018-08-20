/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:45:56 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:21:57 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long taille;
	long nb;

	taille = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (taille <= nb)
		taille = taille * 10;
	taille = taille / 10;
	while (taille > 1)
	{
		ft_putchar_fd((nb / taille) + '0', fd);
		nb = nb % taille;
		taille = taille / 10;
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}
