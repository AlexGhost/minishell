/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:48:19 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/22 13:13:07 by acourtin         ###   ########.fr       */
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

static char		*add_path(char *path, char *bin)
{
	char			*tmp;
	char			*tmpp;

	tmp = ft_strjoin(path, "/");
	tmpp = ft_strjoin(tmp, bin);
	ft_strdel(&tmp);
	return (tmpp);
}

static char		*delete_path(char *str)
{
	int			i;
	int			slash;
	char		*res;

	i = 0;
	slash = 0;
	while (str[i])
	{
		if (str[i] == '/')
			slash = i;
		i++;
	}
	i = slash == 0 ? 0 : slash + 1;
	while (str[i])
		i++;
	res = ft_strnew((i - (slash == 0 ? 0 : slash + 1)) + 1);
	i = slash == 0 ? 0 : slash + 1;
	while (str[i])
	{
		res[i - (slash == 0 ? 0 : slash + 1)] = str[i];
		i++;
	}
	return (res);
}

void			ft_bin(char **tab, t_lstenv **envv)
{
	int				i;
	char			*tmp;
	char			**paths;
	char			*bin;
	t_lstenv		*path;
	DIR				*dir;
	struct dirent	*dir_ent;

	i = 0;
	dir = NULL;
	dir_ent = NULL;
	path = search_key(*envv, "PATH");
	paths = ft_strsplit(path->value, ':');
	bin = delete_path(tab[0]);
	while (paths[i])
	{
		dir = opendir(paths[i]);
		if (dir)
		{
			while ((dir_ent = readdir(dir)))
				if (ft_strcmp(dir_ent->d_name, bin) == 0)
				{
					tmp = add_path(paths[i], bin);
					fork_bin(tmp, tab, envv);
					ft_strdel(&tmp);
				}
			closedir(dir);
		}
		i++;
	}
	megastrdel(paths);
	ft_strdel(&bin);
}
