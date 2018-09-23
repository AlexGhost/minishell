/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:48:19 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 16:52:22 by acourtin         ###   ########.fr       */
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

static void		fork_bin(char *str, char **tab, t_lstenv **envv)
{
	int			i;
	int			pid;
	char		**env;

	env = convert_env(envv);
	pid = fork();
	if (pid == 0)
		execve(str, tab, env);
	wait(NULL);
	i = 0;
	while (env[i])
	{
		ft_strdel(&env[i]);
		i++;
	}
	free(env);
	ft_strdel(&str);
}

static void		megastrdel(char **paths, char *bin)
{
	int i;

	i = 0;
	while (paths[i])
	{
		ft_strdel(&paths[i]);
		i++;
	}
	free(paths);
	ft_strdel(&bin);
}

static void		init_bin(int *i, DIR **dir, struct dirent **dir_ent)
{
	*i = 0;
	dir = NULL;
	dir_ent = NULL;
}

int				ft_bin(char **tab, t_lstenv **envv)
{
	int				i;
	char			**paths;
	char			*bin;
	DIR				*dir;
	struct dirent	*dir_ent;

	init_bin(&i, &dir, &dir_ent);
	if (!search_key(*envv, "PATH"))
		return (0);
	paths = ft_strsplit(search_key(*envv, "PATH")->value, ':');
	bin = delete_path(tab[0]);
	while (paths[i])
	{
		dir = opendir(paths[i]);
		if (dir)
		{
			while ((dir_ent = readdir(dir)))
				if (ft_strcmp(dir_ent->d_name, bin) == 0)
					fork_bin(add_path(paths[i], bin), tab, envv);
			closedir(dir);
		}
		i++;
	}
	megastrdel(paths, bin);
	return (1);
}
