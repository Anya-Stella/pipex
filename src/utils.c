/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:17 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/12 15:27:41 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_split(char **array)
{
	char	**temp;

	if (!array)
		return ;
	temp = array;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(array);
}
