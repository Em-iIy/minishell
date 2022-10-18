/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:32 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 20:45:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

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
