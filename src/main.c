/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:02:09 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/03 19:23:59 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;

	// file２ことコマンド２こをとってきて変数に保存しとくか
	if (ac != 5)
	{
		perror("Not enough arguments.");
		return (1);
	}
	infile = *(++av);
	cmd1 = *(++av);
	cmd2 = *(++av);
	outfile = *(++av);
	
	//　プログラムの実行を行いfileに書き込む
	pipex();

	
	return (0);
}