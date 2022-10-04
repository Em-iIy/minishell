/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:01:02 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/04 14:55:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_token_utils.h"
#include "lexer.h"

void	free_lexer(t_lexer **lexer)
{
	while ((*lexer)->head)
		lexer_token_del(lexer, (*lexer)->head);
	free(*lexer);
}