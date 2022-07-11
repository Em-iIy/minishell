#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft.h"
#include "minishell.h"

int exit_status = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_cmd	cmd;
	pid_t	child;
	int		status;

	(void) argc;
	(void) argv;
	while (1)
	{
		line = readline(">");
		if (line[0] == '\0')
			continue ;
		if (!ft_strncmp(line, "exit", 5))
			return (0);
		cmd = cmd_parse(line, envp);
		if (cmd.cmd)
		{
			child = fork();
			if (child == 0)
			{
				execve(cmd.cmd, cmd.cmd_args, envp);
			}
			waitpid(child, &status, 0);
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
			printf("exit status = %d\n", exit_status);
		}
		printf("%s\nargc = %d\n", line, count_split_cmd(line));
		add_history(line);
		free(line);
	}
}
