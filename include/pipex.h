/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishihar <tishihar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:30:32 by tishihar          #+#    #+#             */
/*   Updated: 2025/02/10 15:01:32 by tishihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
#include <sys/wait.h> 

typedef struct s_cmd
{
	char	*name;
	char	**args;
	char	*path;
} t_cmd;

