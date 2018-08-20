/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:43:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:23:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newptr;
	int		i;
	int		taille;

	i = 0;
	taille = 0;
	while (src[taille] != '\0')
		taille += 1;
	newptr = (char*)malloc(sizeof(*newptr) * taille + 1);
	if (!newptr)
		return (NULL);
	while (src[i] != '\0')
	{
		newptr[i] = src[i];
		i += 1;
	}
	newptr[i] = '\0';
	return (newptr);
}
