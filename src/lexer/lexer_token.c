/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:22:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/08 15:15:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token_utils.h"
#include "lexer.h"
#include "libft.h"

char	*create_next_token(t_token **token, char *line)
{
	t_token	*new;
	int		i;

	new = tok_new(tok_iden(line));
	if (new->iden != DEF)
	{
		if (new->iden == GREATGREAT || new->iden == LESSLESS)
		{
			new->content = ft_substr(line, 0, 2);
			line++;
		}
		else
			new->content = ft_substr(line, 0, 1);
		line++;
	}
	else
	{
		i = 0;
		while (line[i] && tok_iden(&line[i]) == DEF)
			i++;
		new->content = ft_substr(line, 0, i);
		line += i;
	}
	tok_add_back(token, new);
	return (line);
}
