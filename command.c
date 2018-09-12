/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:51:02 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/12 14:20:30 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			free_tab(char **tab)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

static void			ft_exit(int *ex, char **tab, char *error)
{
	if (tab[1])
		ft_strcpy(error, tab[1]);
	*ex = 0;
}

void				read_command(char *l, int *ex, t_lstenv **envv, char *err)
{
	char			**tab;

	if (*l)
	{
		tab = ft_strsplit(l, ' ');
		if (ft_strcmp(tab[0], "exit") == 0)
			ft_exit(ex, tab, err);
		else if (ft_strcmp(tab[0], "echo") == 0)
			ft_echo(tab);
		else if (ft_strcmp(tab[0], "env") == 0)
			ft_showenv(tab, *envv);
		else if (ft_strcmp(tab[0], "setenv") == 0)
			ft_setenv(tab, envv);
		else if (ft_strcmp(tab[0], "unsetenv") == 0)
			ft_unsetenv(tab, envv);
		else if (ft_strcmp(tab[0], "cd") == 0)
			ft_cd(tab, envv);
		free_tab(tab);
	}
}
