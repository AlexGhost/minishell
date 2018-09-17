/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:48:19 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/18 00:25:12 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**convert_env(t_lstenv **envv)
{
	int				i;
	char			*tmp;
	char			**env;
	t_lstenv		*curlist;

	i = 0;
	curlist = *envv;
	while (curlist)
	{
		curlist = curlist->next;
		i++;
	}
	env = ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	curlist = *envv;
	while (curlist)
	{
		tmp = ft_strjoin(curlist->key, "=");
		env[i] = ft_strjoin(tmp, curlist->value);
		ft_strdel(&tmp);
		curlist = curlist->next;
		i++;
	}
	return (env);
}

static void		fork_bin(char *path, char *bin, char **tab, t_lstenv **envv)
{
	int			i;
	int			pid;
	char		*str;
	char		*strr;
	char		**env;

	str = ft_strjoin(path, "/");
	strr = ft_strjoin(str, bin);
	ft_strdel(&str);
	env = convert_env(envv);
	pid = fork();
	if (pid == 0)
		execve(strr, tab, env);
	wait(10);
	i = 0;
	while (env[i])
	{
		ft_strdel(&env[i]);
		i++;
	}
	free(env);
	ft_strdel(&strr);
}

static void		megastrdel(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
	{
		ft_strdel(&paths[i]);
		i++;
	}
	free(paths);
}

void			ft_bin(char **tab, t_lstenv **envv)
{
	int				i;
	char			**paths;
	t_lstenv		*path;
	DIR				*dir;
	struct dirent	*dir_ent;

	i = 0;
	dir = NULL;
	dir_ent = NULL;
	path = search_key(*envv, "PATH");
	paths = ft_strsplit(path->value, ':');
	while (paths[i])
	{
		dir = opendir(paths[i]);
		if (dir)
		{
			while ((dir_ent = readdir(dir)))
				if (ft_strcmp(dir_ent->d_name, tab[0]) == 0)
					fork_bin(paths[i], tab[0], tab, envv);
			closedir(dir);
		}
		i++;
	}
	megastrdel(paths);
}
