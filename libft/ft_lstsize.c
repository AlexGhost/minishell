/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:55:58 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:18:49 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*curlist;

	count = 0;
	curlist = lst;
	if (curlist == NULL)
		return (0);
	while (curlist->next != 0)
	{
		curlist = curlist->next;
		count += 1;
	}
	count += 1;
	return (count);
}
