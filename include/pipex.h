/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/14 13:28:21 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// include
# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	*name;
	char	**args;
	char	*path;
}	t_cmd;

// cmds_init
t_cmd	*create_init_cmds(int ac, char **av, char **envp);
void	destroy_cmds(t_cmd *cmds);

// cmds_run
void	run_cmds(int fd_in, int fd_out, t_cmd *cmds, char **envp);
void	run_exec(int fd_in, int *fd_pipe, t_cmd *_cmd, char **envp);

// get_path
char	*get_path(char **envp, char	*name);

// utils
void	clean_split(char **array);

// test
// void	print_cmds(t_cmd *cmds);
#endif
