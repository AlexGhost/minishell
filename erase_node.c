/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 16:31:49 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 16:33:41 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			erase_node(t_lstenv *node)
{
	ft_strdel(&node->key);
	ft_strdel(&node->value);
	free(node);
}

void			erase_node_lst(t_lstenv **envv, int c)
{
	t_lstenv			*curlist;
	t_lstenv			*nextlist;
	int					i;

	if (c == 0)
	{
		curlist = *envv;
		*envv = curlist->next;
		erase_node(curlist);
	}
	else
	{
		i = 1;
		curlist = *envv;
		nextlist = curlist->next;
		while (i != c)
		{
			curlist = curlist->next;
			nextlist = curlist->next;
			i++;
		}
		curlist->next = nextlist->next;
		erase_node(nextlist);
	}
}
