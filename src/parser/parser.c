/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/22 14:45:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parser_utils.h"

t_parser	*parser(t_token **token)
{
	t_parser	*parser;

	parser = init_parser();
	return (parser);
}
