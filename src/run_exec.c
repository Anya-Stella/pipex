/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/13 15:02:59 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 子プロセスを開き、exec()を実行する関数
void	run_exec(int fd_in, int *fd_pipe, t_cmd *_cmd, char **envp)
{
	pid_t	pid;
	int		fd_out;

	fd_out = fd_pipe[1];
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// いらないFDを閉じる
		close(fd_pipe[0]);
		




		if (fd_in != -1)
		{
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		if (fd_out != -1)
		{
			dup2(fd_out, STDOUT_FILENO);
			close(fd_out);
		}






		if (fd_in == -1)
		{
			// ここは最後のfd_pipe[0]が−１になったとしても入らず、fd_inが-1の場合のみ入る。
			perror("fd_in is not open");
			exit(EXIT_FAILURE);
		}
		if (fd_out == -1)
		{
			// ここは最後のfd_pipe[0]が−１になったとしても入らず、fd_inが-1の場合のみ入る。
			perror("fd_out is not open");
			exit(EXIT_FAILURE);
		}

		execve(_cmd->path, _cmd->args, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
