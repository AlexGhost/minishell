/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:47:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/26 17:24:17 by acourtin         ###   ########.fr       */
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
void					ft_setenv(char **tab, t_lstenv **envv);
void					ft_unsetenv(char **tab, t_lstenv **envv);
void					read_command(char *line, int *ex, t_lstenv **envv);
void					ft_echo(char **tab);
void					lstenv_tail(t_lstenv *lst, t_lstenv *newlst);
void					node_lst(char *line, t_lstenv **env);
void					erase_node(t_lstenv *node);
void					erase_node_lst(t_lstenv **envv, int c);
t_lstenv				*lstenv_new(char *key, char *value);
t_lstenv				*search_key(t_lstenv *envv, char *key);

#endif
