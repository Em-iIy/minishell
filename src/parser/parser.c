/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/13 17:03:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "environment.h"
#include "parser.h"
#include "parser_utils.h"

#include <stdlib.h>
#include <stdio.h>

char	*parse_str(t_env *env, t_lexer **lxr, t_token *head)
{
	char	*ret;
	char	*temp_ret;
	char	*temp;

	ret = ft_calloc(1, 1);
	while (head)
	{
		// printf("1%s\n", head->content);
		if (head->iden == DQUOTE)
			temp = parse_dquote(env, lxr, &head);
		else if (head->iden == QUOTE)
			temp = parse_quote(env, lxr, &head);
		else
			temp = append_token(env, NULL, &head);
		temp_ret = ft_strjoin(ret, temp);
		free(ret);
		free(temp);
		ret = temp_ret;
		if (head->str_end == 1)
			return (ret);
		head = head->next;
	}
	return (ret);
}

t_parser	*parser(t_env *env, t_lexer **lxr)
{
	t_parser	*parser;
	char		*temp;

	parser = init_parser();
	temp = parse_str(env, lxr, (*lxr)->head);
	printf("parsed str: -%s-\n", temp);
	// temp = parser_expand(env, (*lxr)->head->next->next->content);
	// printf("--------%s----------\n", temp);
	free(temp);
	return (parser);
}
