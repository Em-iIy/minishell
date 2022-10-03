/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:16:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/03 14:45:47 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//----------------------------------------Includes
# include "lexer.h"
# include <stdbool.h>

//----------------------------------------Enums
//----------------------------------------Structs
typedef struct s_parser
{
	char	***cmds; // array of commands ready for execve
	int		count; // amount of commands in cmds
	char	*limiter; // take input until limiter
	char	*in; // input file
	char	*out; // output file
	bool	append; // weither to overwrite or append output
}	t_parser;

//----------------------------------------Prototypes
t_parser	*parser(t_token **token);

#endif