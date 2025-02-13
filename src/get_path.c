/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:58:00 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/13 17:30:18 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// envpからkeyの行を見つけ出す関数
static	char	*find_key(char **envp, char	*key)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, key, ft_strlen(key)) == 0)
			return (*envp);
		envp++;
	}
	return (NULL);
}


// env変数から実行pathを見つけ出せ
char	*get_path(char **envp, char	*name)
{
	(void) name;


	char	*path;
	// PATHをgetする
	path = find_key(envp, "PATH");


	return (path);
}
