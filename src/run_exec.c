/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 16:38:09 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 子プロセスを開き、exec()を実行する関数
void	run_exec(int fd_in, int fd_out, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		// フォークにしっぱいしたときの処理はどうするか
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// ここの中は子プロセスだから、fd_inから受取exec,fd_outの流れをやる
		
		// まずdupでプロセスのin,outをつなげる
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

		// exec
		execve(cmd->path, cmd->args, NULL);// 環境変数？

		// exec失敗してプロセスが終わらない場合
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
