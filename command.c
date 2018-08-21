/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:51:02 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/21 15:20:42 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				read_command(char *line, int *ex, t_list *envv)
{
	char		**tab;
	int			i;

	if (*line)
	{
		tab = ft_strsplit(line, ' ');
		if (ft_strcmp(tab[0], "exit") == 0)
			*ex = 1;
		else if (ft_strcmp(tab[0], "echo") == 0)
			ft_echo(tab);
		else if (ft_strcmp(tab[0], "env") == 0)
			ft_showenvv(envv);
		else if (ft_strcmp(tab[0], "cd") == 0)
			ft_cd(tab);
		i = 0;
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
}
