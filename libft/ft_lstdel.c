/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:29:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/05/11 16:17:29 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*curlist;

	curlist = *alst;
	while (curlist->next != NULL)
	{
		del(curlist->content, curlist->content_size);
		free(curlist);
		curlist = curlist->next;
	}
	del(curlist->content, curlist->content_size);
	free(curlist);
	*alst = NULL;
}
