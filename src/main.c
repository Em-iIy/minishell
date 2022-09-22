/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/22 14:44:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "minishell.h"
#include "lexer.h"
#include "parser.h"

static void	check_exit(void)
{
	system("leaks --quiet minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	t_token		*lxr;
	t_parser	*prsr;

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
		prsr = parser(&lxr);
		add_history(line);
		free(line);
	}
}
