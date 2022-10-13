/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:22:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/12 15:48:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token_utils.h"
#include "lexer.h"
#include "libft.h"

#include "debug.h"


/* --find_next_token
Will loop until it finds then next relevent token

if within DOUBLE QUOTES
	loop over all:
		SPACES
		DEFAULT
		SINGLE QUOTES

if within SINGLE QUOTES
	loop until next:
		SINGLE QUOTE

else
	loop over all:
		DEFAULT
Thanks norminette for making this function unreadable and very inefficient :)
*/
static int	find_next_token(t_lexer *lexer, int i)
{
	if (lexer->dquote == 1)
		while (tok_iden(&lexer->line[i]) != TERM && \
		tok_iden(&lexer->line[i]) != DQUOTE && \
		tok_iden(&lexer->line[i]) != EXPAND)
			i++;
	else if (lexer->quote == 1)
		while (tok_iden(&lexer->line[i]) != TERM && \
		tok_iden(&lexer->line[i]) != QUOTE)
			i++;
	else
		while (tok_iden(&lexer->line[i]) != TERM && \
		(tok_iden(&lexer->line[i]) == DEF))
			i++;
	return (i);
}

static void	fill_token(t_lexer **lexer, t_token **token,
						int start_pos, size_t n)
{
	char	*temp;

	temp = ft_substr((*lexer)->line, start_pos, n);
	DEBUG(temp, (*lexer)->dquote, (*lexer)->quote);
	if ((*lexer)->dquote == -1 && (*lexer)->quote == -1)
	{
		(*token)->content = ft_strtrim(temp, "\t\n\v\f\r ");
		if (*(*token)->content == '\0')
		{
			(*token)->iden = -2;
		}
		free(temp);
	}
	else
		(*token)->content = temp;
	(*token)->start_pos = start_pos;
	(*token)->end_pos = start_pos + n;
}

/*
This one's just here because create_next_token() was getting too long
*/
static void	spec_char_token(t_lexer **lexer, t_token **new, int pos)
{
	if ((*new)->iden == DQUOTE)
		(*lexer)->dquote *= -1;
	else if ((*new)->iden == QUOTE)
		(*lexer)->quote *= -1;
	if ((*new)->iden == GREATGREAT || (*new)->iden == LESSLESS)
		fill_token(lexer, new, pos, 2);
	else
		fill_token(lexer, new, pos, 1);
}

static void	check_end(t_lexer *lexer, t_token *token)
{
	char	end;

	if (token->iden == DEF)
		end = lexer->line[token->end_pos - 1];
	else
		end = lexer->line[token->end_pos];
	if (!ft_isspace(end) && end != '\0')
		return ;
	if (lexer->dquote == 1 || lexer->quote == 1)
		return ;
	token->str_end = 1;
}

int	create_next_token(t_lexer **lexer, int pos)
{
	t_token	*new;
	int		i;

	i = 0;
	new = tok_new(tok_iden(&(*lexer)->line[pos]));
	// if
	// (
	// 	( // making sure it's a special char
	// 		new->iden != DEF
	// 		&&
	// 		new->iden != ISSPACE
	// 	)
	// 	&&
	// 	( //
	// 		(*lexer)->quote == -1
	// 		||
	// 		(
	// 			new->iden == QUOTE
	// 			&&
	// 			(*lexer)->dquote == -1
	// 		)
	// 	)
	// 	&&
	// 	(
	// 		(*lexer)->dquote == -1
	// 		||
	// 		(
	// 			new->iden == EXPAND
	// 			&&
	// 			(*lexer)->dquote == 1
	// 		)
	// 		||
	// 		(
	// 			new->iden == DQUOTE
	// 			&&
	// 			(*lexer)->dquote == 1
	// 		)
	// 	)
	// )
	// if ((new->iden == QUOTE && (*lexer)->dquote == -1) || (new->iden != DEF && new->iden != ISSPACE && (*lexer)->quote == -1))
	if ((new->iden != DEF && new->iden != ISSPACE) && ((*lexer)->quote == -1 || (new->iden == QUOTE && (*lexer)->dquote == -1)) && ((*lexer)->dquote == -1 || (new->iden == EXPAND && (*lexer)->dquote == 1) || (new->iden == DQUOTE && (*lexer)->dquote == 1)))
		spec_char_token(lexer, &new, pos);
	else
	{
		i = find_next_token(*lexer, i + pos) - pos;
		fill_token(lexer, &new, pos, i);
		while (ft_isspace((*lexer)->line[new->end_pos]))
			new->end_pos++;
	}
	if (new->iden == -2)
	{
		i = new->end_pos;
		tok_free(&new);
		return (i);
	}
	check_end(*lexer, new);
	tok_add_back(&(*lexer)->head, new);
	return (new->end_pos);
}
