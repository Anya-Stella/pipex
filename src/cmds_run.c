/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 16:39:24 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// cmdsの数だけ子プロセスをwaitする関数
static	void	wait_cmds(t_cmd *cmds)
{
	while (cmds->name)
	{
		wait(NULL);
		cmds++;
	}
}

// fd_inとfd_outを入出力先としてcmds（複数）を実行する関数
void	run_cmds(int fd_in, int fd_out, t_cmd *cmds)
{
	int		fd_pipe[2];// fd_pipe[0]が出ていく側、fd_pipe[1]が書き込む側
	int		prev_fd;
	t_cmd	*temp;

	prev_fd = fd_in;
	temp = cmds;
	while (cmds->name)
	{
		// pipe設定
		if ((cmds + 1)->name)
			pipe(fd_pipe);
		else
		{
			fd_pipe[0] = -1;
			fd_pipe[1] = fd_out;
		}

		// フォークして、子プロセス側でexecしてくれる関数
		run_exec();// 入ってくるFD(prev_fd)と書き込むべきFD(fd_pipe[1])がわたされる。

		//close
		close(prev_fd);
		close(fd_pipe[1]);

		// 割当
		prev_fd = fd_pipe[0];
		
		cmds++;	
	}
	wait_cmds(temp);
}
