/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:15:32 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/13 12:14:12 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_brexit(char *str, int error)
{
	perror(str);
	exit(error);
}

void	error_access(void)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	// ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": permission denied \n", STDERR_FILENO);
	exit(126); //not an executable
}

void	error_command(void)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd("command not found\n", STDERR_FILENO);
	exit(127); //command no found
}
