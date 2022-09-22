/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/21 17:00:29 by gwinnink         ###   ########.fr       */
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
	int				end_pos;
	int				start_pos;
	char			*content;
	struct s_token	*next;	
	struct s_token	*prev;	
}	t_token;

typedef struct s_lexer
{
	t_token			*head;
	char			*line;
	int				quote;
	int				dquote;
}	t_lexer;

//----------------------------------------Prototypes
t_token	*lexer(char *line);
int		create_next_token(t_lexer **lexer, int pos);

#endif