/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/25 15:48:23 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int			ft_execenv(char **tab, t_lstenv *envv)
{
	int			i;
	int			r;
	char		*str;
	t_lstenv	*tmp;

	i = 1;
	r = 0;
	while (tab[i])
	{
		if (!ft_strchr(tab[i], '='))
			r = 1;
		i++;
	}
	str = tab_to_str(tab);
	str[ft_strlen(str)] = '\0';
	if (str)
	{
		cpy_lst(&tmp, envv);
		read_command(str, NULL, &tmp, NULL);
		free_lst(tmp);
	}
	return (r);
}

void				ft_showenv(char **tab, t_lstenv *envv)
{
	t_lstenv		*doublelst;
	t_lstenv		*curlist;
	t_lstenv		*prevlist;

	doublelst = NULL;
	cpy_lst(&doublelst, envv);
	ft_setenv(tab, &doublelst);
	if (!ft_execenv(tab, doublelst))
	{
		curlist = doublelst;
		while (curlist)
		{
			ft_putstr(curlist->key);
			ft_putchar('=');
			ft_putendl(curlist->value);
			prevlist = curlist;
			curlist = curlist->next;
		}
	}
	free_lst(doublelst);
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
