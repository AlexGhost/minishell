/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:47:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 19:04:33 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef struct			s_lstenv
{
	char				*key;
	char				*value;
	struct s_lstenv		*next;
}						t_lstenv;

int						ft_cd(char **tab);
void					ft_showenv(char **tab, t_lstenv *envv);
void					ft_setenv(char **tab, t_lstenv *envv);
void					ft_unsetenv(char **tab, t_lstenv *envv);
void					read_command(char *line, int *ex, t_lstenv *envv);
void					ft_echo(char **tab);
void					lstenv_tail(t_lstenv *lst, t_lstenv *newlst);
t_lstenv				*lstenv_new(char *key, char *value);

#endif
