/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/11 15:39:47 by tishihar         ###   ########.fr       */
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

static	int	init_cmds(t_cmd *cmds, int ac, char **av, int len_cmds)
{
	av += 2;
	while (len_cmds--)
	{
		*cmds->args = ft_split(*av, ' ');
		if (*cmds->args == NULL)
		{
			perror("split failed");
			return (1);
		}
		*cmds->name = *cmds->args[0];// "ls"
		*cmds->path = NULL;
		cmds++;
		av++;
	}
	return (0);
}

int	create_init_cmds(int ac, char **av)
{
	t_cmd	*cmds;
	int		len_cmds;

	len_cmds = ac - 3;
	cmds = create_cmds(len_cmds);
	if (!cmds)
		return (1);
	if (init_cmds(cmds, ac, av, len_cmds) == 1)
	{
		destroy_cmds(cmds);
		return (1);
	}
	return (0);
}

void	destroy_cmds(t_cmd *cmds)
{
	t_cmd	*origin;

	origin = cmds;
	while (cmds)
	{
		if (cmds->args)
			clean_split(cmds->args);
		cmds++;
	}
	free(origin);
}
