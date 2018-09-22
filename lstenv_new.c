/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstenv_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 18:25:10 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/22 18:16:58 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void					free_lst(t_lstenv *lst)
{
	t_lstenv		*curlist;
	t_lstenv		*prevlist;

	curlist = lst;
	while (curlist)
	{
		prevlist = curlist;
		curlist = curlist->next;
		erase_node(prevlist);
	}
}

void					lstenv_tail(t_lstenv *lst, t_lstenv *newlst)
{
	t_lstenv		*curlist;

	curlist = lst;
	if (curlist)
	{
		while (curlist->next)
			curlist = curlist->next;
		curlist->next = newlst;
	}
	else
		lst = newlst;
}

t_lstenv				*lstenv_new(char *key, char *value)
{
	t_lstenv		*lst;

	if (!(lst = ft_memalloc(sizeof(t_lstenv))))
		return (NULL);
	if (!(lst->key = ft_memalloc(sizeof(char) * (ft_strlen(key) + 1))))
		return (NULL);
	else
		lst->key = ft_strcpy(lst->key, key);
	if (!(lst->value = ft_memalloc(sizeof(char) * (ft_strlen(value) + 1))))
		return (NULL);
	else
		lst->value = ft_strcpy(lst->value, value);
	return (lst);
}

void					cpy_lst(t_lstenv **dest, t_lstenv *src)
{
	t_lstenv			*curlist;

	curlist = src;
	if (curlist)
	{
		*dest = lstenv_new(curlist->key, curlist->value);
		curlist = curlist->next;
		while (curlist)
		{
			lstenv_tail(*dest, lstenv_new(curlist->key, curlist->value));
			curlist = curlist->next;
		}
	}
}
