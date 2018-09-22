/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:25:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/22 13:26:10 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*add_path(char *path, char *bin)
{
	char			*tmp;
	char			*tmpp;

	tmp = ft_strjoin(path, "/");
	tmpp = ft_strjoin(tmp, bin);
	ft_strdel(&tmp);
	return (tmpp);
}

char			*delete_path(char *str)
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
