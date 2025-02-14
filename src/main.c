/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:09 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/14 20:01:57 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmds;
	int		fd_in;
	int		fd_out;

	if (ac < 5)
	{
		perror("Not enough arguments.");
		return (1);
	}
	cmds = create_init_cmds(ac, av, envp);
	if (!cmds)
	{
		perror("init cmds failed");
		return (1);
	}
	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	run_cmds(fd_in, fd_out, cmds, envp);
	destroy_cmds(cmds);
	return (0);
}

// pathの確認用
// printf("path is: %s \n",get_path(envp, "ls"));
