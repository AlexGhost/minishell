/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:48:23 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 17:43:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_showenv(char **tab, t_list *envv)
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

static void			del_content_one(t_list *envv, char *str)
{
	t_list			*curlist;

	curlist = envv;
	if (ft_strequ(curlist->content, str))
	{
		free(curlist->content);
		curlist->content = NULL;
		envv = curlist->next;
		curlist->next = NULL;
		free(curlist);
	}
}

static void			del_content(t_list *envv, char *str)
{
	t_list			*curlist;
	t_list			*nextlist;

	del_content_one(envv, str);
	curlist = envv;
	nextlist = curlist->next;
	while (curlist && nextlist)
	{
		if (ft_strequ(nextlist->content, str))
		{
			free(nextlist->content);
			nextlist->content = NULL;
			curlist->next = nextlist->next;
			nextlist->next = NULL;
			free(nextlist);
		}
		curlist = curlist->next;
		if (curlist)
			nextlist = curlist->next;
	}
}

void				ft_unsetenv(char **tab, t_list *envv)
{
	t_list			*curlist;
	char			*str;
	int				i;

	curlist = envv;
	while (curlist)
	{
		i = 1;
		while (tab[i])
		{
			str = ft_strjoin(tab[i], "=");
			ft_putendl(str);
			if (ft_strstr(curlist->content, str))
				del_content(envv, curlist->content);
			ft_strdel(&str);
			i++;
		}
		curlist = curlist->next;
	}
}
