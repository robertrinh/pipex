/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 16:04:08 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/26 17:13:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **seek_path(char *envp[])
{
    char    *temp_path;
    
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[j], "PATH=", ft_strlen(envp[j])))
            break;
        i++;
        j++;
    }
    if (!envp[i])
        error_handler("no ENVP");
    temp_path = ft_substr(envp[j], 5, ft_strlen(envp[j]));
    return (ft_split(temp_path, ':'));
}

char    **get_path(char *envp[], t_pipex pepe)
{
    int i;
    
    i = 0;
    pepe.path = seek_path(envp);
    if(!pepe.path)
        error_handler("no path");
    while (pepe.path[i])
    {
        pepe.path[i] = gnl_strjoin(pepe.path[i], "/");
        i++;
    }
    return(pepe.path);
}