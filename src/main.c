/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/06 16:31:49 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "environment.h"

static void	check_exit(void)
{
	system("leaks --quiet minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**new_envp;
	t_lexer		*lxr;
	t_parser	*prsr;
	t_env		*env;
	int			i;

	i = 0;
	env = env_cpy(envp);
	new_envp = make_envp(env);
	while (envp[i])
	{
		printf("old:%s\n", envp[i]);
		printf("new:%s\n", new_envp[i]);
		i++;
	}
	atexit(check_exit);
	while (1)
	{
		line = readline("minishell>");
		if (!line)
			return (0);
		if (line[0] == '\0')
			continue ;
		if (!ft_strncmp(line, "exit", 5))
		{
			printf("exit\n");
			exit(0);
		}
		lxr = lexer(line); // need to write free function for token list!!!!!!!!!!
		// prsr = parser(&lxr);
		free_lexer(&lxr);
		add_history(line);
		free(line);
	}
}
