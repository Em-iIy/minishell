/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:46 by gwinnink          #+#    #+#             */
/*   Updated: 2022/07/13 15:20:47 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_cmd
{
	char	*cmd;
	char	**cmd_args;
}	t_cmd;

//----------------------------------------Prototypes
t_cmd	cmd_parse(char *line, char **envp);
int		count_split_cmd(char *line);

#endif