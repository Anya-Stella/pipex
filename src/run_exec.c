/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:58 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 19:37:53 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 子プロセスを開き、exec()を実行する関数
void	run_exec(int fd_in, int fd_out, t_cmd *_cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
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
		execve(_cmd->path, _cmd->args, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
