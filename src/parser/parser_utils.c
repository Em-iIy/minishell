/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:34:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/13 17:17:17 by gwinnink         ###   ########.fr       */
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
	ret->limiter = NULL;
	ret->in = NULL;
	ret->out = NULL;
	ret->append = 0;
	return (ret);
}

char	*parser_expand(t_env *env, char *str)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	temp = ft_substr(str, 0, i);
	ret = ft_strjoin(get_env(env, temp), &str[i]);
	if (!ret)
		ret = ft_strdup(&str[i]);
	free(temp);
	return (ret);
}

char	*append_token(t_env *env, char *str, t_token **token)
{
	char	*ret;
	char	*temp;

	if ((*token)->iden == EXPAND && (*token)->next->iden == DEF)
	{
			temp = parser_expand(env, (*token)->next->content);
			(*token) = (*token)->next;
	}
	else if ((*token)->iden == EXPAND && !str)
		temp = ft_strdup("");
	else
		temp = ft_strdup((*token)->content);
	// printf("hi\n");
	if (!str)
		ret = ft_strdup(temp);
	else
	{
		ret = ft_strjoin(str, temp);
		free(str);
	}
	free(temp);
	return (ret);
}
