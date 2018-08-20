/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:22:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:24:03 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	unsigned long	i;
	int				taille;

	i = 0;
	taille = 0;
	while (dest[taille] != '\0')
		taille += 1;
	while (src[i] != '\0' && i < nb)
	{
		dest[taille + i] = src[i];
		i += 1;
	}
	dest[taille + i] = '\0';
	return (dest);
}
