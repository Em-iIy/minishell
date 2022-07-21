/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:12:00 by gwinnink          #+#    #+#             */
/*   Updated: 2022/07/21 15:27:00 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "minishell.h"
#include <stdbool.h>
#include <stdio.h>

// checks if the char c is a character that should be split on
bool	is_split(char c)
{
	if (c == '\'' || c == '\"' || c == ' ')
		return (true);
	return (false);
}

int	count_split_cmd(char *line)
{
	char	*temp;
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*line)
	{
		if (is_split(*line))
		{
			temp = ft_strchr(line + 1, *line);
			if (!temp)
				return (0);
			if (!*temp && *line != ' ')
				return (0); // in case of unclosed qoute
			else if (temp[1] == *line)
				temp = ft_strchr(temp + 2, *line);
			line = temp + 1;
			count++;
		}
	}
	return (count);
}

// static char **split_cmd(char *line)
// {
// 	char	**ret;
// 	int		count;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	count = count_split_cmd(line);
// 	ret = (char **)malloc((count + 1) * sizeof(char *));
// 	if (!ret)
// 		return (NULL);
// 	while (i < count)
// 	{
// 		j = 0;
// 		while 
// 	}
// }

static char	*check_cmd(char *cmd, char **path)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	if (!cmd || !path)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		ret = ft_strjoin(temp, cmd);
		free(temp);
		if (access(ret, X_OK) == 0)
		{
			ft_free_all(path);
			return (ret);
		}
		free(ret);
		i++;
	}
	ft_free_all(path);
	return (NULL);
}

t_cmd	cmd_parse(char *line, char **envp)
{
	t_cmd	cmd;
	int		i;

	i = 0;
	printf("minishell argc = %d\n", count_split_cmd(line));
	cmd.cmd_args = ft_split(line, ' ');
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			cmd.cmd = check_cmd(cmd.cmd_args[0], ft_split(envp[i], ':'));
			break ;
		}
		i++;
	}
	return (cmd);
}
