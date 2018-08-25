/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 19:41:49 by acourtin         ###   ########.fr       */
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

void				ft_setenv(char **tab, t_lstenv *envv)
{
	/*t_lstenv			*curlist;
	t_lstenv			*newlist;
	char			**tabi;
	int				i;
	int				j;

	curlist = envv;
	i = 1;
	while (tab[i])
	{
		tabi = ft_strsplit(tab[i], '=');
		if (tabi[1] && tabi[2] == NULL)
		{
			newlist = ft_lstnew(tab[i], ft_strlen(tab[i]));
			ft_lsttail(&curlist, newlist);
		}
		i++;
		j = 0;
		while (tabi[j])
		{
			ft_strdel(&tabi[j]);
			j++;
		}
		free(tabi);
	}*/
}

void				ft_unsetenv(char **tab, t_lstenv *envv)
{
	/*
	* check que la key dans tab existe dans la liste
	* si ca existe pas finir la fonction
	* si ca existe del le maillon ou y a cette key
	 */
}
