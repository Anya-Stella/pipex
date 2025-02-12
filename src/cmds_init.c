/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 15:17:01 by tishihar         ###   ########.fr       */
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

static	int	init_cmds(t_cmd *_cmd, char **av, int len_cmds)
{
	av += 2;
	while (len_cmds--)
	{
		_cmd->args = ft_split(*av, ' ');
		if (_cmd->args == NULL)
		{
			perror("split failed");
			return (1);
		}
		_cmd->name = _cmd->args[0];// "ls"
		_cmd->path = NULL;
		_cmd++;
		av++;
	}
	return (0);
}

t_cmd	*create_init_cmds(int ac, char **av)
{
	t_cmd	*cmds;
	int		len_cmds;

	len_cmds = ac - 3;
	cmds = create_cmds(len_cmds);
	if (!cmds)
		return (NULL);
	if (init_cmds(cmds, av, len_cmds) == 1)
	{
		destroy_cmds(cmds);
		return (NULL);
	}
	return (cmds);
}

void	destroy_cmds(t_cmd *_cmd)
{
	t_cmd	*origin;

	origin = _cmd;
	while (_cmd->name)
	{
		clean_split(_cmd->args);
		_cmd++;
	}
	free(origin);
}
