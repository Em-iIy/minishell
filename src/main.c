/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/08 15:17:48 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"
#include "minishell.h"
#include "lexer.h"

int exit_status = 0;

static void check_exit(void)
{
	system("leaks --quiet minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_cmd	cmd;
	pid_t	child;
	int		status;

	(void) argc;
	(void) argv;
	atexit(check_exit);
	while (1)
	{
		line = readline("minishell>");
		if (!line)
			return (0);
		if (line[0] == '\0')
			continue ;
		if (!ft_strncmp(line, "exit", 5))
			exit(0);
		lexer(line); // need to write free function for token list!!!!!!!!!!
		// cmd = cmd_parse(line, envp);
		// if (cmd.cmd)
		// {
		// 	child = fork();
		// 	if (child == 0)
		// 	{
		// 		execve(cmd.cmd, cmd.cmd_args, envp);
		// 	}
		// 	free(cmd.cmd);
		// 	waitpid(child, &status, 0);
		// 	if (WIFEXITED(status))
		// 		exit_status = WEXITSTATUS(status);
		// 	// printf("exit status = %d\n", exit_status);
		// }
		// ft_free_all(cmd.cmd_args);
		// printf("%s\nargc = %d\n", line, count_split_cmd(line));
		add_history(line);
		free(line);
	}
}
