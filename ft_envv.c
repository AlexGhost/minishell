/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 15:54:56 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_showenv(char **tab, t_lstenv *envv)
{
	t_lstenv			*curlist;

	curlist = envv;
	while (curlist)
	{
		ft_putstr(curlist->key);
		ft_putchar('=');
		ft_putendl(curlist->value);
		curlist = curlist->next;
	}
}

void				ft_setenv(char **tab, t_lstenv **envv)
{
	int				i;
	t_lstenv		*tmp;

	i = 1;
	while (tab[i])
	{
		if (ft_strchr(tab[i], '='))
		{
			node_lst(tab[i], &tmp);
			lstenv_tail(*envv, tmp);
		}
		i++;
	}
}

static void			erase_node(t_lstenv *node)
{
	ft_strdel(&node->key);
	ft_strdel(&node->value);
	free(node);
}

static void			erase_node_lst(t_lstenv **envv, int c)
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

void				ft_unsetenv(char **tab, t_lstenv **envv)
{
	int				i;
	int				c;
	t_lstenv		*curlist;

	i = 1;
	curlist = *envv;
	while (tab[i])
	{
		curlist = *envv;
		c = 0;
		while (curlist)
		{
			if (!ft_strcmp(tab[i], curlist->key))
				erase_node_lst(envv, c);
			curlist = curlist->next;
			c++;
		}
		i++;
	}
}
