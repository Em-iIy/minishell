/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/03 13:18:15 by gwinnink         ###   ########.fr       */
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
t_lexer	*lexer(char *line);
int		create_next_token(t_lexer **lexer, int pos);
void	free_lexer(t_lexer **lexer);

#endif