/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:01:53 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/20 18:03:57 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		loopshell(char *line, int *ex)
{
	ft_putstr("_>");
	line = ft_memalloc(sizeof(char) * 4096);
	get_next_line(STDIN_FILENO, &line);
	read_command(line, ex);
}

int			main(void)
{
	int			ex;
	char		*line;

	ex = 0;
	line = NULL;
	while (ex == 0)
		loopshell(line, &ex);
	return (0);
}
