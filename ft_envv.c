/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/22 16:20:12 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			replace_node(t_lstenv *first, t_lstenv *second)
{
	ft_strcpy(first->value, second->value);
	erase_node(second);
}

void				ft_setenv(char **tab, t_lstenv **envv)
{
	int				i;
	t_lstenv		*tmp;
	t_lstenv		*dup;

	i = 1;
	while (tab[i])
	{
		dup = NULL;
		if (ft_strchr(tab[i], '='))
		{
			node_lst(tab[i], &tmp);
			if ((ft_strlen(tmp->key) > 0 && ft_strlen(tmp->value) > 0) \
				&& !(ft_strchr(tmp->key, '=')))
			{
				if ((dup = search_key(*envv, tmp->key)))
					replace_node(dup, tmp);
				else
					lstenv_tail(*envv, tmp);
			}
			else
				erase_node(tmp);
		}
		i++;
	}
}

void				ft_showenv(char **tab, t_lstenv *envv)
{
	t_lstenv		*doublelst;
	t_lstenv		*curlist;
	t_lstenv		*prevlist;

	doublelst = NULL;
	cpy_lst(&doublelst, envv);
	if (tab[1])
		ft_setenv(tab, &doublelst);
	curlist = doublelst;
	while (curlist)
	{
		ft_putstr(curlist->key);
		ft_putchar('=');
		ft_putendl(curlist->value);
		prevlist = curlist;
		curlist = curlist->next;
		erase_node(prevlist);
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
