/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/15 15:26:03 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_token_utils.h"
#include "libft.h"

t_token	*lexer(char *line)
{
	t_lexer	*lex_head;
	int		i;

	lex_head->head = NULL;
	lex_head->line = line;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
		i = create_next_token(&lex_head, i);
	lexer_token_print(lex_head->head);
	return (lex_head->head);
}
