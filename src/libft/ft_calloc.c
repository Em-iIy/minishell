/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 18:00:51 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, size_t size)
{
	unsigned int	i;
	char			*ret;

	ret = (void *)malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}
