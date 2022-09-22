/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:23:30 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/21 14:50:27 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_TOKEN_UTILS_H
# define LEXER_TOKEN_UTILS_H

# include "lexer.h"

//----------------------------------------Prototypes
int		tok_iden(char *c);
t_token	*tok_new(int iden);
t_token	*tok_last(t_token *token);
void	tok_add_back(t_token **token, t_token *new);
void	print_list_tokens(t_token *head);
void	lexer_token_print(t_token *token);
int	tok_free(t_token **token);

#endif