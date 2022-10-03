/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:01:02 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/03 14:26:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_token_utils.h"
#include "lexer.h"

void	free_lexer(t_lexer **lexer)
{
	t_token	*temp;
	t_token	*head;

	head = (*lexer)->head;
	temp = head->next;
	tok_free(&head);
	while (temp)
	{
		head = temp;
		temp = head->next;
		tok_free(&head);
	}
	free(*lexer);
}
