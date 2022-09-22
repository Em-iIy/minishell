/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/21 16:57:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_token_utils.h"
#include "libft.h"

static t_lexer	*init_lexer(char *line)
{
	t_lexer	*ret;

	ret = (t_lexer *)malloc(sizeof(t_lexer));
	if (!ret)
		exit(1);
	ret->head = 0;
	ret->line = line;
	ret->quote = -1;
	ret->dquote = -1;
	return (ret);
}

t_token	*lexer(char *line)
{
	t_lexer	*lex_head;
	int		i;

	lex_head = init_lexer(line);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
		i = create_next_token(&lex_head, i);
	lexer_token_print(lex_head->head);
	return (lex_head->head);
}
