/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:16:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:14 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//----------------------------------------Includes
# include "environment.h"
# include "lexer.h"
# include <stdbool.h>

//----------------------------------------Enums
//----------------------------------------Structs
typedef struct s_file
{
	struct s_file	*next;
	char			*file_name;
	int				fd;
	bool			io;
	bool			alt;
}	t_file;

typedef struct s_cmd
{
	struct s_cmd	*next;
	t_file			*files;
	char			**command;
}	t_cmd;

typedef struct s_parser
{
	t_cmd	*cmds; // list of commands ready for execve
	int		count; // amount of commands in cmds
}	t_parser;

//----------------------------------------Prototypes
t_parser	*parser(t_env *env, t_lexer **lxr);

#endif