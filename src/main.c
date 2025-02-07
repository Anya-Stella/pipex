/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:09 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/07 17:53:10 by tishihar         ###   ########.fr       */
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
	
	

	
	// 入力FDから受け取って、cmdを実行(run_prarail)、出力fdに書き込むメイン処理　を何回かループ　-----------------------
	// normalでいいなら「入力ー＞exec->出力」を２回やればいい

	int	prev_fd;
	prev_fd = fd_in;

	int	fd_pipe[2];// fd_pipe[0]が出ていく側、fd_pipe[1]が書き込む側
	while (cmds)// コマンドの回数ぶん
	{
		// pipeをつくる
		if (cmds + 1 != NULL)
			//　次もcmdある時
			pipe(fd_pipe);
		else
		{
			// 次は書き込みの時(例えばcmdが１つだとしたら)
			
			
		}

		

		// フォークして、子プロセス側でexecしてくれる関数
		run_plarail();// 入ってくるFD(prev_fd)と書き込むべきFD(fd_pipe[1])がわたされる。




		//ここは親プロセスのやることをやる
		// 子プロセス側で今使ったのでもう使わないのでprev_fdは閉じる。
		close (prev_fd);


		// 継続ならprev_fdの再定義、さいごなら今使ったfd_outを閉じる
		if (cmds + 1 != NULL)
			prev_fd = fd_pipe[1];
		else
			close (fd_out);
		
		
		


		cmds++;
	}
	
	// wait()処理










	
	// メイン処理終了------------------------------------------------------------------------------

	// fd_inとfd_outをcloseせなばな
	close(fd_in);
	close(fd_out);
	// cmdsを開放する
	clean_cmds();

	
	return (0);
}


//TODO：　それぞれの関数openとかに対して、エラーハンドリングすること



