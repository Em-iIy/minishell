/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:25:55 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/05 17:56:25 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

//----------------------------------------Structs
typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*val;
}	t_env;

//----------------------------------------Prototypes
t_env	*env_cpy(char **envp);
char	**make_envp(t_env *env);

#endif