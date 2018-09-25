/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:44:44 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/25 15:48:32 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				replace_node(t_lstenv *first, t_lstenv *second)
{
	ft_strcpy(first->value, second->value);
	erase_node(second);
}

char				*tab_to_str(char **tab)
{
	int				i;
	int				j;
	int				k;
	char			*str;

	str = ft_strnew(get_tab_length(tab));
	i = 0;
	k = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "env"))
		{
			j = 0;
			while (tab[i][j])
			{
				str[k] = tab[i][j];
				j++;
				k++;
			}
			str[k] = ' ';
			k++;
		}
		i++;
	}
	return (str);
}

int					get_tab_length(char **tab)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "env"))
		{
			j = 0;
			while (tab[i][j])
				j++;
			k += j + 2;
		}
		i++;
	}
	return (k);
}
