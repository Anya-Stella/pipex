/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:46:47 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/11 17:34:34 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_cmds(t_cmd *cmds)
{
	while (cmds->name != NULL)
	{
		// name
		printf("Command name: %s\n", cmds->name);

		// args
		if (cmds->args)
		{
			int j = 0;
			printf("args: ");
			while (cmds->args[j] != NULL)
			{
				printf("[%s] ", cmds->args[j]);
				j++;
			}
			printf("\n");
		}
		else
		{
			printf("args: (null)\n");
		}

		// path
		if (cmds->path)
			printf("path: %s\n", cmds->path);
		else
			printf("path: (null)\n");

		printf("----\n");
		cmds++; // 次の要素へ進む
	}
}
