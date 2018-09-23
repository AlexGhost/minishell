/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_expense.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:05:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 20:21:34 by acourtin         ###   ########.fr       */
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

static void		copy_and_incr(char *strun, char *strdeux, int *i, int *j)
{
	strun[*i] = strdeux[*j];
	*i += 1;
	*j += 1;
}

char			*remplace_variable(char *line, t_lstenv **envv)
{
	int			i;
	int			j;
	int			k;
	char		*tmp;
	char		*res;

	i = 0;
	k = 0;
	res = ft_strnew(4096);
	while (line[i])
	{
		if (line[i] == '$' && !is_delim(line[i + 1]))
		{
			i++;
			j = 0;
			tmp = ft_strnew(4096);
			while (!is_delim(line[i]))
				copy_and_incr(tmp, line, &j, &i);
			tmp[j] = '\0';
			if (search_key(*envv, tmp))
			{
				j = 0;
				while (search_key(*envv, tmp)->value[j])
					copy_and_incr(res, search_key(*envv, tmp)->value, &k, &j);
			}
			ft_strdel(&tmp);
		}
		else
			copy_and_incr(res, line, &k, &i);
	}
	return (res);
}
