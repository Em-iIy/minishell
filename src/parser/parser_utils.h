/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:31:11 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/13 16:15:32 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

//----------------------------------------Includes
# include "parser.h"
# include "environment.h"

//----------------------------------------Prototypes
t_parser	*init_parser(void);
char		*parser_expand(t_env *env, char *str);
char		*append_token(t_env *env, char *str, t_token **token);
char		*parse_dquote(t_env *env, t_lexer **lxr, t_token **token);
char		*parse_quote(t_env *env, t_lexer **lxr, t_token **token);

#endif