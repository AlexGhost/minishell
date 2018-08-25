/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 14:52:23 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_showenvv(char **tab, t_list *envv)
{
	t_list			*curlist;

	curlist = envv;
	while (curlist)
	{
		ft_putendl(curlist->content);
		curlist = curlist->next;
	}
}

void				ft_setenv(char **tab, t_list *envv)
{
	t_list			*curlist;
	t_list			*newlist;
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
	}
}

void				ft_unsetenv(char **tab, t_list *envv)
{
}
