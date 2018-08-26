/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 16:32:10 by acourtin         ###   ########.fr       */
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
			if ((ft_strlen(tmp->key) > 0 && ft_strlen(tmp->value) > 0) \
				&& !(ft_strchr(tmp->key, '=') || ft_strchr(tmp->value, '=')))
				lstenv_tail(*envv, tmp);
			else
				erase_node(tmp);
		}
		i++;
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
