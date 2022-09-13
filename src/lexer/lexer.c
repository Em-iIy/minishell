/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/13 14:55:23 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "lexer_token_utils.h"
#include "libft.h"

t_token	*lexer(char *line)
{
	t_token	*head;

	head = NULL;
	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		line = create_next_token(&head, line);
	}
	lexer_token_print(head);
	return (head);
}
