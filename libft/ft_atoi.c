/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:16:00 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:16:09 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	res = 0;
	neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i += 1;
	}
	else if (str[i] == '+')
		i += 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res += (str[i] - 48);
		i += 1;
	}
	return (res * neg);
}
