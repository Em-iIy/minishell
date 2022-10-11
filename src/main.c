/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/11 13:13:10 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
	while (new_envp[i])
	{
		printf("--%s\n", new_envp[i]);
		i++;
	}
	if (argc == 2)
	{
		printf("getenv->%s=\"%s\"\n", argv[1], getenv(argv[1]));
		printf("get_env->%s=\"%s\"\n", argv[1], get_env(env, argv[1]));
	}
	else if (argc == 3)
	{
		add_env(&env, argv[1], argv[2]);
		ft_free_all(new_envp);
		new_envp = make_envp(env);
		printf("get_env->%s=\"%s\"\n", argv[1], get_env(env, argv[1]));
	}
	else if (argc == 4)
	{
		unset_env(&env, argv[1]);
		ft_free_all(new_envp);
		new_envp = make_envp(env);
		printf("get_env->%s=\"%s\"\n", argv[1], get_env(env, argv[1]));
	}
	// i = 0;
	// while (new_envp[i])
	// {
	// 	printf("new:%s\n", new_envp[i]);
	// 	i++;
	// }
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
