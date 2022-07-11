#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_cmd
{
	char	*cmd;
	char	**cmd_args;
}	t_cmd;

//----------------------------------------Prototypes
t_cmd	cmd_parse(char *line, char **envp);
int	count_split_cmd(char *line);

#endif