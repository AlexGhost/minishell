/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:19 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:20:39 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = -1;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (psrc < pdst)
	{
		while ((int)--len >= 0)
			pdst[len] = psrc[len];
	}
	else
	{
		while (++i < len)
			pdst[i] = psrc[i];
	}
	return (dst);
}
