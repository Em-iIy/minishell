#include <unistd.h>
#include "libft.h"
#include "minishell.h"
#include <stdbool.h>

int	count_split_cmd(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == 39)
		{
			i++;
			if (line[i] != 39)
			{
				while (line[i] != 39 && line[i])
					i++;
				if (!line[i])
					return (-1);
				count++;
			}
			else
				i++;
		}
		else if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == 0))
			count++;
		i++;
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

static char *check_cmd(char *cmd, char **path)
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
		temp  = ft_strjoin(path[i], "/");
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
	return (NULL);
}

t_cmd   cmd_parse(char *line, char **envp)
{
    t_cmd   cmd;
    int     i;

    i = 0;
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