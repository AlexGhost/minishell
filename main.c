/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 19:40:58 by acourtin         ###   ########.fr       */
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

static t_lstenv		*malloc_lst(char *line)
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
	return (lstenv_new(key, value));
}

static t_lstenv		*cpy_env(char **tab)
{
	int				i;
	int				j;
	t_lstenv		*envv;

	i = 1;
	envv = malloc_lst(tab[0]);
	while (tab[i])
	{
		lstenv_tail(envv, malloc_lst(tab[i]));
		i++;
	}
	return (envv);
}

int				main(int ac, char **av, char **env)
{
	int				ex;
	t_lstenv		*envv;

	ex = 0;
	//envv = NULL;
	envv = cpy_env(env);
	while (ex == 0)
		loopshell(&ex, envv);
	return (0);
}
