/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/13 15:30:48 by tishihar         ###   ########.fr       */
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
// fd_pipe[0]が出ていく側、fd_pipe[1]が書き込む側
// run_execには、パイプの書き込み口と、入力側(prev_fd)をわたす。
void	run_cmds(int fd_in, int fd_out, t_cmd *cmds, char **envp)
{
	int		fd_pipe[2];
	int		prev_fd;
	t_cmd	*temp;

	prev_fd = fd_in;
	temp = cmds;
	while (cmds->name)
	{
		if ((cmds + 1)->name)
			pipe(fd_pipe);
		else
		{
			fd_pipe[0] = -1;
			fd_pipe[1] = fd_out;
		}
		run_exec(prev_fd, fd_pipe, cmds, envp);
		close(prev_fd);
		close(fd_pipe[1]);
		prev_fd = fd_pipe[0];
		cmds++;
	}
	wait_cmds(temp);
}
