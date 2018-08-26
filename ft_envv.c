/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 15:27:59 by acourtin         ###   ########.fr       */
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

void				ft_unsetenv(char **tab, t_lstenv *envv)
{
}
