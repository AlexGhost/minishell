/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:07:35 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/21 16:02:40 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_cd(char **tab)
{
	int		cd;
	char	*cdchar;
	char	*cwd;

	cd = -55;
	if (tab[1])
	{
		cd = chdir(tab[1]);
		cdchar = ft_itoa(cd);
		ft_putstr("code chdir = ");
		ft_putendl(cdchar);
		ft_strdel(&cdchar);
	}
	return (cd);
}
