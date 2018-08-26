/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 14:19:03 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		loopshell(int *ex, t_lstenv *envv)
{
	char			*line;

	ft_putstr("_>");
	get_next_line(STDIN_FILENO, &line);
	read_command(line, ex, envv);
	ft_strdel(&line);
}

static void		malloc_lst(char *line, t_lstenv **env)
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
	i = 0;
	while (line[k])
	{
		value[i] = line[k];
		i++;
		k++;
	}
	*env = lstenv_new(key, value);
	ft_strdel(&key);
	ft_strdel(&value);
}

static void		cpy_env(char **tab, t_lstenv **env)
{
	int				i;
	int				j;
	t_lstenv		*envv;
	t_lstenv		*tmp;

	i = 1;
	malloc_lst(tab[0], &envv);
	while (tab[i])
	{
		malloc_lst(tab[i], &tmp);
		lstenv_tail(envv, tmp);
		i++;
	}
	*env = envv;
}

int				main(int ac, char **av, char **env)
{
	int				ex;
	t_lstenv		*envv;

	ex = 0;
	cpy_env(env, &envv);
	while (ex == 0)
		loopshell(&ex, envv);
	return (0);
}
