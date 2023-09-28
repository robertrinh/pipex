/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:04:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/28 17:58:40 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
			return (ft_substr(envp[i], 5, ft_strlen(envp[i] - 5)));
		i++;
	}
	return (NULL);	
}

/**
 * @brief splits PATH by executable ":", returns array of directories
 * @param envp the enviromental path
 * @param t_pipex the struct to store the path
 * @return the path (array of directories)
*/
char	**get_path(char **envp, t_pipex *pepe)
{
	char	*env_path;
	char	**split_path;

	env_path = parse_env(envp);
	if (!env_path)
		error_brexit("no path", errno);
	split_path = ft_split(env_path, ':');
	if (!pepe->path)
		error_brexit("split fail", errno);
	free(env_path);
	return (split_path);
}

char	*correct_path_cmd(char **envp, t_pipex *pepe, char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK) == 0)
			return(ft_strdup(cmd));
		return (NULL);
	}
	return (get_cmd(envp, pepe, cmd));
}

char	*get_cmd(char **envp, t_pipex *pepe, char *cmd)
{
	int	i;
	char	*temp;
	char	*arg_path;
	char	*cmd_args;

	i = 0;
	while (pepe->path[i])
	{
		temp = ft_strjoin("/", cmd);
		if (!temp)
			error_brexit("malloc", errno);
		arg_path = ft_strjoin(pepe->path, temp);
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

void	exe_cmd_paths(t_pipex *pepe, )




// char	**seek_path(char *envp[])
// {
// 	char	*temp_path;
// 	int		i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
// 			break ;

// 		i++;
// 	}
// 	if (!envp[i])
// 		error_handler("no ENVP");
// 	temp_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
// 	return (ft_split(temp_path, ':'));
// }

// char	**get_cmd(char *envp[], t_pipex pepe)
// {
// 	int i;

// 	i = 0;
// 	pepe.path = seek_path(envp);
// 	// printf("path is: %s \n", pepe.path[i]);
// 	if (!pepe.path)
// 		error_handler("no path");
// 	while (pepe.path[i])
// 	{
// 		pepe.path[i] = ft_strjoin(pepe.path[i], "/");
// 		// printf("path after strjoin: %s \n", pepe.path[i]);
// 		i++;
// 	}
// 	return (pepe.path);
// }