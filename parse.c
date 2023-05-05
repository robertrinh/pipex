/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:04:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/05/05 17:28:43 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> //delete afterwards
char	**seek_path(char *envp[])
{
	char	*temp_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			break ;

		i++;
	}
	if (!envp[i])
		error_handler("no ENVP");
	temp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	return (ft_split(temp_path, ':'));
}

char	**get_cmd(char *envp[], t_pipex pepe)
{
	int i;

	i = 0;
	pepe.path = seek_path(envp);
	// printf("path is: %s \n", pepe.path[i]);
	if (!pepe.path)
		error_handler("no path");
	while (pepe.path[i])
	{
		pepe.path[i] = ft_strjoin(pepe.path[i], "/");
		// printf("path after strjoin: %s \n", pepe.path[i]);
		i++;
	}
	return (pepe.path);
}