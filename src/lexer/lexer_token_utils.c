/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:38 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/21 14:50:19 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

int	tok_iden(char *c)
{
	if (c[0] == '\0')
		return (-1);
	else if (ft_isspace(c[0]))
		return (0);
	else if (c[0] == '>')
	{
		if (c[1] == '>')
			return (GREATGREAT);
		return (GREAT);
	}
	else if (c[0] == '<')
	{
		if (c[1] == '<')
			return (LESSLESS);
		return (LESS);
	}
	else if (c[0] == '\'')
		return (QUOTE);
	else if (c[0] == '\"')
		return (DQUOTE);
	else if (c[0] == '|')
		return (PIPE);
	else if (c[0] == '$')
		return (EXPAND);
	return (DEF);
}

t_token	*tok_new(int iden)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));
	if (!ret)
		exit(1);
	ret->content = NULL;
	ret->next = NULL;
	ret->prev = NULL;
	ret->iden = iden;
	return (ret);
}

int	tok_free(t_token **token)
{
	int	ret;

	ret = (*token)->end_pos;
	free((*token)->content);
	free(*token);
	return (ret);
}

t_token	*tok_last(t_token *token)
{
	while (token)
	{
		if (!token->next)
			return (token);
		token = token->next;
	}
	return (token);
}

void	tok_add_back(t_token **token, t_token *new)
{
	t_token	*temp;

	if (!*token)
		*token = new;
	else
	{
		temp = tok_last(*token);
		temp->next = new;
		new->prev = temp;
	}
}
