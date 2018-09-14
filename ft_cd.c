/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:07:35 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/14 16:41:57 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		change_env_pwd(char *cwd, t_lstenv *oldpwd, t_lstenv *pwd)
{
	getcwd(cwd, 4096);
	ft_putendl(cwd);
	ft_strdel(&oldpwd->value);
	oldpwd->value = ft_strjoin(pwd->value, "");
	ft_strdel(&pwd->value);
	pwd->value = ft_strjoin(cwd, "");
	ft_strdel(&cwd);
}

void			ft_cd(char **tab, t_lstenv **envv)
{
	int			ichdir;
	char		*cwd;
	t_lstenv	*oldpwd;
	t_lstenv	*pwd;
	t_lstenv	*home;

	home = search_key(*envv, "HOME");
	oldpwd = search_key(*envv, "OLDPWD");
	pwd = search_key(*envv, "PWD");
	if (tab[1])
	{
		if (ft_strequ(tab[1], "-"))
			ichdir = chdir(oldpwd->value);
		else
			ichdir = chdir(tab[1]);
	}
	else
		ichdir = chdir(home->value);
	if (ichdir == 0)
	{
		cwd = ft_strnew(4096);
		if (pwd && oldpwd)
			change_env_pwd(cwd, oldpwd, pwd);
	}
}
