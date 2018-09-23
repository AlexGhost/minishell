/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:47:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/09/23 20:05:52 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include "libft.h"

typedef struct			s_lstenv
{
	char				*key;
	char				*value;
	struct s_lstenv		*next;
}						t_lstenv;

void					ft_cd(char **tab, t_lstenv **envv);
void					ft_showenv(char **tab, t_lstenv *envv);
void					ft_setenv(char **tab, t_lstenv **envv);
void					ft_unsetenv(char **tab, t_lstenv **envv);
void					read_command(char *l, int *ex, t_lstenv **envv, \
							char *err);
void					ft_echo(char **tab);
void					lstenv_tail(t_lstenv *lst, t_lstenv *newlst);
void					node_lst(char *line, t_lstenv **env);
void					erase_node(t_lstenv *node);
void					erase_node_lst(t_lstenv **envv, int c);
void					cpy_lst(t_lstenv **dest, t_lstenv *src);
void					free_lst(t_lstenv *lst);
int						ft_bin(char **tab, t_lstenv **envv);
char					*add_path(char *path, char *bin);
char					*delete_path(char *str);
char					*remplace_variable(char *line, t_lstenv **envv);
t_lstenv				*lstenv_new(char *key, char *value);
t_lstenv				*search_key(t_lstenv *envv, char *key);

#endif
