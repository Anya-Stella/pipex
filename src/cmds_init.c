/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:32:15 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/14 14:26:32 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	t_cmd	*create_cmds(int len_cmds)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_calloc(len_cmds + 1, sizeof(t_cmd));
	if (!cmds)
		return (NULL);
	return (cmds);
}

// cmdsを初期化する関数。nameはlsとかcwとか。
static	int	init_cmds(t_cmd *_cmd, char **av, int len_cmds, char **envp)
{
	av += CMDS_OFFSET;
	while (len_cmds--)
	{
		_cmd->args = ft_split(*av, ' ');
		if (_cmd->args == NULL)
		{
			perror("split failed");
			return (1);
		}
		_cmd->name = _cmd->args[0];
		_cmd->path = get_path(envp, _cmd->name);
		_cmd++;
		av++;
	}
	return (0);
}

// cmdsを確保し初期化する。
t_cmd	*create_init_cmds(int ac, char **av, char **envp)
{
	t_cmd	*cmds;
	int		len_cmds;

	len_cmds = ac - EXEPT_CMDS_VOLUME;
	cmds = create_cmds(len_cmds);
	if (!cmds)
		return (NULL);
	if (init_cmds(cmds, av, len_cmds, envp) == 1)
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
		free(_cmd->path);
		_cmd++;
	}
	free(origin);
}
