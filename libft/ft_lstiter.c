/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:59:40 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:17:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*curlist;

	if (lst)
	{
		curlist = lst;
		while (curlist->next != NULL)
		{
			f(curlist);
			curlist = curlist->next;
		}
		f(curlist);
	}
}
