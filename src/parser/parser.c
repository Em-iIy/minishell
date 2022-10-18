/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 19:43:01 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "parser_utils.h"
#include "parse_cmd_utils.h"

#include <stdlib.h>
#include <stdio.h>

static void	print_cmd(t_cmd *cmd)
{
	int		i;
	t_file	*file;

	i = 0;
	file = cmd->files;
	if (!cmd)
		return ;
	printf("cmd: ");
	while (cmd->command[i])
	{
		printf("`%s` ", cmd->command[i]);
		i++;
	}
	printf("\n");
	while (file)
	{
		if (file->io == false)
		{
			if (file->alt == false)
				printf("in: ");
			else
				printf("hd.: ");
		}
		else
		{
			if (file->alt == false)
				printf("out: ");
			else
				printf("app.: ");
		}
		printf("'%s' =>\t", file->file_name);
		file = file->next;
	}
	printf("\n");
}

static void	print_prsr(t_parser *prsr)
{
	t_cmd	*temp;

	temp = prsr->cmds;
	printf("cmd count: %d", prsr->count);
	while (temp)
	{
		printf("\n-----------------------------------------------------\n");
		print_cmd(temp);
		temp = temp->next;
	}
}

/*
this function should set exit code to 258 if false
*/
static bool	check_cmd(t_cmd *cmd, t_token *token)
{
	if ((!*cmd->command && !cmd->files) || \
		(token && token->iden == PIPE && !token->next))
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (false);
	}
	return (true);
}

t_parser	*parser(t_env *env, t_lexer **lxr)
{
	t_parser	*parser;
	t_cmd		*temp;
	t_token		*tok_temp;

	parser = init_parser();
	tok_temp = (*lxr)->head;
	while (tok_temp && parser->count != -1)
	{
		temp = parse_cmd(env, lxr, &tok_temp);
		if (!temp || check_cmd(temp, tok_temp) == false)
		{
			parser->count = -1;
			// return (parser);
		}
		if (tok_temp)
			tok_temp = tok_temp->next;
		parser->count++;
		cmd_add_back(&parser->cmds, temp);
	}
	print_prsr(parser);
	return (parser);
}
