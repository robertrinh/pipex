/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:15:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/21 17:44:05 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    error_brexit(char *str, int error)
{
    perror(str);
    exit(error);
}

void error_access(char *path)
{
    ft_putstr_fd("pipex: ", STDERR_FILENO);
    ft_putstr_fd(path, STDERR_FILENO);
    ft_putstr_fd(": permission denied \n", STDERR_FILENO);
    exit(126); //not an executable
}

void    error_path(char *cmd)
{
    ft_putstr_fd("pipex: ", STDERR_FILENO);
    ft_putstr_fd(cmd, STDERR_FILENO);
    ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
    exit(127); //command no found
}

