/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/20 19:46:55 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		loopshell(char *line, int *ex, t_list *envv)
{
	ft_putstr("_>");
	line = ft_memalloc(sizeof(char) * 4096);
	get_next_line(STDIN_FILENO, &line);
	read_command(line, ex, envv);
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
	char		*line;
	t_list		*envv;

	ex = 0;
	line = NULL;
	envv = NULL;
	cpy_env(env, &envv);
	while (ex == 0)
		loopshell(line, &ex, envv);
	return (0);
}
