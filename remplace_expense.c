/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_expense.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 20:05:11 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 20:52:55 by acourtin         ###   ########.fr       */
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

static void		search_and_copy(t_lstenv *envv, char *tmp, char *res, int *k)
{
	int			j;

	if (search_key(envv, tmp))
	{
		j = 0;
		while (search_key(envv, tmp)->value[j])
			copy_and_incr(res, search_key(envv, tmp)->value, k, &j);
	}
}

void			remplace_var(char *line, t_lstenv **envv, char *tmp, char *res)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '$' && !is_delim(line[i + 1]))
		{
			i++;
			j = 0;
			while (!is_delim(line[i]))
				copy_and_incr(tmp, line, &j, &i);
			tmp[j] = '\0';
			search_and_copy(*envv, tmp, res, &k);
		}
		else if (line[i] == '~')
		{
			i++;
			search_and_copy(*envv, "HOME", res, &k);
		}
		else
			copy_and_incr(res, line, &k, &i);
	}
}
