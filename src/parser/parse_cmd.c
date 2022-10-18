/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 16:18:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "parse_cmd_utils.h"
#include "parser_utils.h"
#include "parser.h"

#include "debug.h"

static char	*add_cmd(char *cmds, char *new)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(cmds, " ");
	if (!temp)
		return (NULL);
	free(cmds);
	ret = ft_strjoin(temp, new);
	if (!ret)
		return (NULL);
	free(temp);
	return (ret);
}

t_cmd	*parse_cmd(t_env *env, t_lexer **lxr, t_token **head)
{
	t_cmd	*ret;
	char	*temp;

	temp = (char *)ft_calloc(1, 1);
	ret = cmd_new();
	while (*head && (*head)->iden != PIPE)
	{
		DEBUG("loop start", 0, 0);
		if ((*head)->iden == GREAT || (*head)->iden == GREATGREAT || \
			(*head)->iden == LESS || (*head)->iden == LESSLESS)
		{
			DEBUG("if", 0, 0);
			DEBUG((*head)->content, (*head)->start_pos, (*head)->end_pos);
			ret->files = parse_io(env, lxr, head);
			if (!ret->files)
				return (NULL);
			DEBUG((*head)->content, (*head)->start_pos, (*head)->end_pos);
		}
		else if (check_valid_str_iden((*head)->iden, (*head)->content))
		{
			DEBUG("else if", 0, 0);
			DEBUG((*head)->content, (*head)->start_pos, (*head)->end_pos);
			temp = add_cmd(temp, parse_str(env, lxr, head));
			if (!temp)
				return (NULL);
			DEBUG((*head)->content, (*head)->start_pos, (*head)->end_pos);
		}
		(*head) = (*head)->next;
		DEBUG("loop end", 0, 0);
	}
	DEBUG("post loop", 0, 0);
	// if (*head)
	// 	DEBUG((*head)->content, (*head)->start_pos, (*head)->end_pos);
	// else if ((*head)->prev)
	// 	DEBUG((*head)->prev->content, 1, 1);
	ret->command = ft_split(temp, ' ');
	free(temp);
	return (ret);
}
