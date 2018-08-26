/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:44:25 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 17:34:49 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_echo(char **tab)
{
	int i;
	int noendl;

	i = 1;
	noendl = 0;
	if (tab[i])
		if (!ft_strcmp(tab[i], "-n"))
		{
			i++;
			noendl = 1;
		}
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	if (tab[i])
		ft_putstr(tab[i]);
	if (noendl == 0)
		ft_putchar('\n');
}
