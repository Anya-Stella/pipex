/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/10 18:00:34 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	t_cmd	*create_cmds(int len_cmds)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_calloc(len_cmds + 1, sizeof(t_cmd));// cmd1,cmd2,\0;
	if (!cmds)
		return (NULL);
	return (cmds);
}

static	void	init_cmds(t_cmd *cmds, int ac, char **av, int len_cmds)
{
	av++;
	



	while (cmds)
	{
		*cmds->name = *av;




		cmds++;
	}
}



void	create_init_cmds(int ac, char **av)
{
	t_cmd	*cmds;
	int		len_cmds;

	len_cmds = ac - 3;
	cmds = create_cmds(len_cmds);
	if (!cmds)
		return (0);
	
	// init処理
	init_cmds(cmds, ac, av, len_cmds);
}

















void	clean_cmds()
{

}
