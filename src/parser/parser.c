/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/04 12:12:15 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

t_parser	*parser(t_lexer **lxr)
{
	t_parser	*parser;

	parser = init_parser();
	return (parser);
}
