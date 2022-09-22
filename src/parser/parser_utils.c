/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:34:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/09/22 14:44:40 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

t_parser	*init_parser(void)
{
	t_parser	*ret;

	ret = (t_parser *)malloc(sizeof(t_parser));
	if (!ret)
		exit(-1);
	ret->cmds = NULL;
	ret->count = 0;
	ret->limiter = NULL;
	ret->in = NULL;
	ret->out = NULL;
	ret->append = 0;
	return (ret);
}
