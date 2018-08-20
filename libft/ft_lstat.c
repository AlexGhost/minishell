/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:01:06 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:17:17 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstat(t_list *lst, unsigned int nbr)
{
	if (!lst)
		return (NULL);
	else if (nbr == 0)
		return (lst);
	else if (lst->next != 0)
		return (ft_lstat(lst->next, nbr - 1));
	return (NULL);
}
