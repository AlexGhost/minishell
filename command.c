/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:51:02 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/20 18:09:20 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				read_command(char *line, int *ex)
{
	char		**tab;

	if (*line)
	{
		tab = ft_strsplit(line, ' ');
		if (ft_strcmp(tab[0], "exit") == 0)
			*ex = 1;
		else if (ft_strcmp(tab[0], "echo") == 0)
			ft_echo(tab);
		ft_strdel(&line);
		free(line);
	}
}
