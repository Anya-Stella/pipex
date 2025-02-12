/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 16:09:48 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
} t_cmd;


// cmds_init
t_cmd	*create_init_cmds(int ac, char **av);
void	destroy_cmds(t_cmd *cmds);

// cmds_run
void	run_cmds(int fd_in, int fd_out, t_cmd *cmds);

// utils
void	clean_split(char **array);

// test
// void	print_cmds(t_cmd *cmds);
