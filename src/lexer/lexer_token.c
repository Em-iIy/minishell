/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:22:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/15 15:27:35 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token_utils.h"
#include "lexer.h"
#include "libft.h"

static void	fill_token(t_lexer **lexer, t_token **token,
						int start_pos, size_t n)
{
	char	*temp;

	temp = ft_substr((*lexer)->line, start_pos, n);
	(*token)->content = ft_strtrim(temp, "\t\n\v\f\r ");
	if (*(*token)->content == '\0' && \
		((*lexer)->dquote == 1 || (*lexer)->quote == 1))
	{
		free((*token)->content);
		(*token)->content = temp;
	}
	else
		free(temp);
	(*token)->start_pos = start_pos;
	(*token)->end_pos = start_pos + n;
}

int	create_next_token(t_lexer **lexer, int pos)
{
	t_token	*new;
	int		i;

	i = 0;
	new = tok_new(tok_iden(&(*lexer)->line[pos + i]));
	if (new->iden != DEF)
	{
		if (new->iden == GREATGREAT || new->iden == LESSLESS)
			fill_token(lexer, &new, pos, 2);
		else
			fill_token(lexer, &new, pos, 1);
	}
	else
	{
		while ((*lexer)->line[pos + i] && tok_iden(&(*lexer)->line[pos + i]) == DEF)
			i++;
		fill_token(lexer, &new, pos, i);
		while (ft_isspace((*lexer)->line[new->end_pos]))
			new->end_pos++;
	}
	tok_add_back(&(*lexer)->head, new);
	return (new->end_pos);
}
