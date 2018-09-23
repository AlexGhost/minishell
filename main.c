/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 16:35:05 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		loopshell(int *ex, t_lstenv **envv, char *err)
{
	char			*line;

	ft_putstr("_>");
	get_next_line(STDIN_FILENO, &line);
	read_command(line, ex, envv, err);
}

static void		node_value(int k, char *line, char *value)
{
	int i;

	i = 0;
	while (line[k])
	{
		value[i] = line[k];
		i++;
		k++;
	}
}

void			node_lst(char *line, t_lstenv **env)
{
	int			i;
	int			j;
	int			k;
	char		*key;
	char		*value;

	i = 0;
	while (line[i] != '=')
		i++;
	key = ft_strnew(i);
	ft_strncpy(key, line, i);
	i++;
	j = i;
	k = i;
	while (line[i])
		i++;
	j = i - j;
	value = ft_strnew(j);
	node_value(k, line, value);
	*env = lstenv_new(key, value);
	ft_strdel(&key);
	ft_strdel(&value);
}

static void		cpy_env(char **tab, t_lstenv **env)
{
	int				i;
	t_lstenv		*envv;
	t_lstenv		*tmp;

	i = 1;
	node_lst(tab[0], &envv);
	while (tab[i])
	{
		node_lst(tab[i], &tmp);
		lstenv_tail(envv, tmp);
		i++;
	}
	*env = envv;
}

int				main(int ac, char **av, char **env)
{
	int				ex;
	char			*error;
	t_lstenv		*envv;

	ex = -1;
	error = ft_strjoin("", "0");
	cpy_env(env, &envv);
	ft_putendl("=== Minishell ===");
	while (ex == -1)
		loopshell(&ex, &envv, error);
	free_lst(envv);
	exit(ft_atoi(error));
	return (0);
}
