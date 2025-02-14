/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:58:00 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/14 13:24:37 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*find_value(char *str, int shift)
{
	return (str + shift);
}

// envpからkeyの行を見つけ出し、valueを返す関数
static	char	*get_value_by_key(char **envp, char	*key)
{
	int	len;

	len = ft_strlen(key);
	while (*envp)
	{
		if (ft_strncmp(*envp, key, len) == 0)
			return (find_value(*envp, len + 1));
		envp++;
	}
	return (NULL);
}

// pathを連結する関数
static	char	*join_path(char *dir, char *name)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, name);
	free(temp);
	return (result);
}

// vallidateしてアクセス権があるものを出力する
static	char	*validate_and_get_path(char **paths, char *name)
{
	char	*curr_path;

	curr_path = NULL;
	while (*paths)
	{
		curr_path = join_path(*paths, name);
		if (!curr_path)
			return (NULL);
		if (access(curr_path, X_OK) == 0)
			return (curr_path);
		free(curr_path);
		paths++;
	}
	return (NULL);
}

// env変数から実行pathを見つけ出せ
// row is: "PATH=/home/tishihar/bin:/home/tish...
char	*get_path(char **envp, char	*name)
{
	char	**path;
	char	*result;

	path = ft_split(get_value_by_key(envp, "PATH"), ':');
	if (!path)
		return (NULL);
	result = validate_and_get_path(path, name);
	if (!result)
	{
		clean_split(path);
		return (NULL);
	}
	clean_split(path);
	return (result);
}
