/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 13:56:58 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "parser_utils.h"
#include "parse_cmd_utils.h"

#include <stdlib.h>
#include <stdio.h>


t_parser	*parser(t_env *env, t_lexer **lxr)
{
	t_parser	*parser;
	// char		*temp;
	t_cmd		*temp;
	t_token		*temp_head;

	parser = init_parser();
	temp_head = (*lxr)->head;
	temp = parse_cmd(env, lxr, &temp_head);
	// temp = parse_str(env, lxr, &temp_head);
	// printf("parsed str: -%s-\n", temp);
	cmd_free(temp);
	return (parser);
}
