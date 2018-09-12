/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:07:35 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/12 16:34:28 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_cd(char **tab, t_lstenv **envv)
{
	char		*cwd;
	t_lstenv	*oldpwd;
	t_lstenv	*pwd;

	if (tab[1])
	{
		chdir(tab[1]);
		cwd = ft_strnew(4096);
		oldpwd = search_key(*envv, "OLDPWD");
		pwd = search_key(*envv, "PWD");
		if (pwd && oldpwd)
		{
			getcwd(cwd, 4096);
			ft_putendl(cwd);
			ft_strdel(&oldpwd->value);
			oldpwd->value = ft_strjoin(pwd->value, "");
			ft_strdel(&pwd->value);
			pwd->value = ft_strjoin(cwd, "");
			ft_strdel(&cwd);
		}
	}
}
