/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:47:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/21 14:11:18 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

int 					ft_cd(char **tab);
int						ft_strcmp_deb(const char *s1, const char *s2);
void					ft_showenvv(t_list *envv);
void					read_command(char *line, int *ex, t_list *envv);
void					ft_echo(char **tab);

#endif
