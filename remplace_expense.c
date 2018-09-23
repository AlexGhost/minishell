/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_expense.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:05:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 20:05:33 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_delim(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '=' || c == '\0' || c == '$'
		|| c == '/')
		return (1);
	return (0);
}

char			*remplace_variable(char *line, t_lstenv **envv)
{
	int			i;
	int			j;
	int			k;
	char		*tmp;
	char		*newline;

	i = 0;
	k = 0;
	newline = ft_strnew(4096);
	while (line[i])
	{
		if (line[i] == '$' && !is_delim(line[i + 1]))
		{
			i++;
			j = 0;
			tmp = ft_strnew(4096);
			while (!is_delim(line[i]))
			{
				tmp[j] = line[i];
				i++;
				j++;
			}
			tmp[j] = '\0';
			if (search_key(*envv, tmp))
			{
				j = 0;
				while (search_key(*envv, tmp)->value[j])
				{
					newline[k] = search_key(*envv, tmp)->value[j];
					j++;
					k++;
				}
			}
			ft_strdel(&tmp);
		}
		else
		{
			newline[k] = line[i];
			k++;
			i++;
		}
	}
	return (newline);
}
