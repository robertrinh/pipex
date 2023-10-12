/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:04:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/10/06 17:30:43 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h> //delete

/**
 * @brief seeks if PATH exists in env
 * @param envp enviromental path
 * @return substring of the found PATH. returns NULL if not found (unset)
*/
static char	*parse_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
		i++;
	}
	return (NULL);	
}

/**
 * @brief splits PATH by executable ":", returns split array of directories
 * @param envp the enviromental path
 * @param t_pipex the struct to store the path
 * @return the path (array of directories)
*/
char	**get_path(char **envp)
{
	char	*env_path;
	char	**split_path;

	env_path = parse_env(envp);
	if (!env_path)
		error_brexit("no path", errno);
	split_path = ft_split(env_path, ':');
	if (!split_path)
		error_brexit("split fail", errno);
	free(env_path);
	return (split_path);
}

/**
 * @brief finds command through two ways; either the absolute path (./...) or relative path
 * @param t_pipex the struct which contains path
 * @param cmd the command used
 * @return strdup of absolute command in case / or . is found and if command exists or
 * @return relative path in case absolute is not found
*/
char	*correct_path_cmd(t_pipex *pepe, char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	else
		return (get_cmd(pepe, cmd));
}
/**
 * @brief loops through parsed envp to find the cmd
 * @param t_pipex the struct which has path stored
 * @param cmd the command used
 * @return location of the executable after in case file exists
 * @return or NULL in case not found
*/
char	*get_cmd(t_pipex *pepe, char *cmd)
{
	int	i;
	char	*temp;
	char	*arg_path;

	i = 0;
	while (pepe->path[i])
	{
		temp = ft_strjoin("/", cmd);
		if (!temp)
			error_brexit("malloc", errno);
		arg_path = ft_strjoin(pepe->path[i], temp);
		if (!arg_path)
			error_brexit("malloc", errno);
		free(temp);
		if (access(arg_path, F_OK) == 0)
			return (arg_path);
		free(arg_path);
		i++;
	}
	return (NULL);
}
