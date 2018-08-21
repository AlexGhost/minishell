/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/21 15:31:00 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		loopshell(int *ex, t_list *envv)
{
	char			*line;

	ft_putstr("_>");
	get_next_line(STDIN_FILENO, &line);
	read_command(line, ex, envv);
	ft_strdel(&line);
}

void		cpy_env(char **env, t_list **envv)
{
	int		i;
	int		j;
	t_list	*curlist;

	j = 0;
	curlist = NULL;
	while (env[0][j])
		j++;
	if (env[0])
		*envv = ft_lstnew(env[0], j + 1);
	i = 1;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
			j++;
		if (env[i])
		{
			curlist = ft_lstnew(env[i], j + 1);
			ft_lsttail(envv, curlist);
		}
		i++;
	}
}

int			main(int ac, char **av, char **env)
{
	int			ex;
	t_list		*envv;

	ex = 0;
	envv = NULL;
	cpy_env(env, &envv);
	while (ex == 0)
		loopshell(&ex, envv);
	return (0);
}
