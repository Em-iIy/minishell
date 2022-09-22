/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:22:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/21 15:44:27 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token_utils.h"
#include "lexer.h"
#include "libft.h"

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
		while (tok_iden(&lexer->line[i]) != -1 && \
		(tok_iden(&lexer->line[i]) == 0 || tok_iden(&lexer->line[i]) == DEF || \
		tok_iden(&lexer->line[i]) == QUOTE))
			i++;
	else if (lexer->quote == 1)
		while (tok_iden(&lexer->line[i]) != -1 && \
		tok_iden(&lexer->line[i]) != QUOTE)
			i++;
	else
		while (tok_iden(&lexer->line[i]) != -1 && \
		(tok_iden(&lexer->line[i]) == DEF))
			i++;
	return (i);
}

static void	fill_token(t_lexer **lexer, t_token **token,
						int start_pos, size_t n)
{
	char	*temp;

	temp = ft_substr((*lexer)->line, start_pos, n);
	if ((*lexer)->dquote == -1 && (*lexer)->quote == -1)
	{
		(*token)->content = ft_strtrim(temp, "\t\n\v\f\r ");
		if (*(*token)->content == '\0')
		{
			free(temp);
			(*token)->iden = -2;
		}
	}
	else
		(*token)->content = temp;
	(*token)->start_pos = start_pos;
	(*token)->end_pos = start_pos + n;
}

int	create_next_token(t_lexer **lexer, int pos)
{
	t_token	*new;
	int		i;

	i = 0;
	new = tok_new(tok_iden(&(*lexer)->line[pos + i]));
	if (new->iden != DEF && new->iden != 0)
	{
		if (new->iden == DQUOTE)
			(*lexer)->dquote *= -1;
		else if (new->iden == QUOTE)
			(*lexer)->quote *= -1;
		if (new->iden == GREATGREAT || new->iden == LESSLESS)
			fill_token(lexer, &new, pos, 2);
		else
			fill_token(lexer, &new, pos, 1);
	}
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
		free(new);
		return (i);
	}
	tok_add_back(&(*lexer)->head, new);
	return (new->end_pos);
}
