/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:34:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:09 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "environment.h"
#include "parser.h"

#include <stdio.h>
#include <unistd.h>

t_parser	*init_parser(void)
{
	t_parser	*ret;

	ret = (t_parser *)malloc(sizeof(t_parser));
	if (!ret)
		exit(-1);
	ret->cmds = NULL;
	ret->count = 0;
	return (ret);
}
