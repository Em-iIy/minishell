/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/08 14:09:31 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

//----------------------------------------Enums
enum e_iden
{
	GREAT = 1,
	GREATGREAT,
	LESS,
	LESSLESS,
	QUOTE,
	DQUOTE,
	PIPE,
	EXPAND,
	DEF
};

//----------------------------------------Structs
typedef struct s_token
{
	int				iden;
	char			*content;
	struct s_token	*next;	
	struct s_token	*prev;	
}	t_token;

//----------------------------------------Prototypes
t_token	*lexer(char *line);
char	*create_next_token(t_token **token, char *line);

#endif