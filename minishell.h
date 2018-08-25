/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <acourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 15:47:39 by acourtin          #+#    #+#             */
/*   Updated: 2018/08/25 14:34:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

int						ft_cd(char **tab);
void					ft_showenvv(char **tab, t_list *envv);
void					ft_setenv(char **tab, t_list *envv);
void					read_command(char *line, int *ex, t_list *envv);
void					ft_echo(char **tab);

#endif
