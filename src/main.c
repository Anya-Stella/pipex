/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:09 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/10 17:12:00 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_cmd	*cmds;
	int		fd_in;
	int		fd_out;

	// コマンドライン引数チェック
	if (ac != 5)
	{
		perror("Not enough arguments.");
		return (1);
	}

	// cmds初期化
	cmds = create_init_cmds(ac, av);

	// file_open
	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);

	// run_cmds
	run_cmds(fd_in, fd_out, cmds);
	
	// cmdsを開放する
	clean_cmds();
	
	return (0);
}


//TODO：　それぞれの関数openとかに対して、エラーハンドリングすること



