/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/13 15:24:23 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	check_fd(int fd_in, int fd_out)
{
	if (fd_in == -1)
	{
		perror("fd_in is not open");
		exit(EXIT_FAILURE);
	}
	if (fd_out == -1)
	{
		perror("fd_out is not open");
		exit(EXIT_FAILURE);
	}
}

static	void	setup_child_fd(int fd_in, int fd_out)
{
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
}

// 子プロセスを開き、exec()を実行する関数
// どうして、子プロセス側でパイプの読み取り側をクローズする必要があるのか？
// 親側も含め、fd_pipe[0]は三箇所ひらいている。
// 親側と今回の子側のfd_pipe[0]を閉じることで残り１つのpipe[0](次のプロセスの入力)が閉じると、読み込み側がすべて閉じきる仕組みを作れる。
// 書き込みが不可能になるので、プロセスが終了する。
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
		close(fd_pipe[0]);
		setup_child_fd(fd_in, fd_out);
		check_fd(fd_in, fd_out);
		execve(_cmd->path, _cmd->args, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
