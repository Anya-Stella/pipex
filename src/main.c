/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:09 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/10 17:08:41 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// pipeはcmdの数に関わらず１個を親側で使い回せる。
// cmdを２つローカル変数にするか。。。
int	main(int ac, char **av)
{
	// cmdsにはcmdの数だけcmd構造体を入れる。
	t_cmd	*cmds;
	int		fd_in;
	int		fd_out;

	// コマンドライン引数チェック
	if (ac != 5)
	{
		perror("Not enough arguments.");
		return (1);
	}

	// init＿cmdsする。つまりリストのなかのcmdsをそれぞれ初期化して使えるようにする。
	// cmdsはcmd構造体のリストである。
	// ここでは、cmdリストをcreateして初期化するところまで。
	cmds = create_init_cmds(ac, av);// 今回は２個かな



	// fd_inとfd_outは間違いなく開いておく必要がある。
	// パーミッションは777
	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);


	// run_cmds
	run_cmds(fd_in, fd_out, cmds);
	
	// cmdsを開放する
	clean_cmds();
	
	return (0);
}


//TODO：　それぞれの関数openとかに対して、エラーハンドリングすること



