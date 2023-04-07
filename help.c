/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 11:42:10 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/07 17:54:29 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(char *error_msg, t_pipex *pipex)
{
	free(pipex);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	pepe_init(t_pipex *pipex)
{
	pipex = ft_calloc(sizeof(t_pipex), 1);
	if(!pipex)
		return (NULL);
	pipex->fd1 = NULL;
	pipex->fd2 = NULL;
	pipex->argv = NULL;
	pipex->envp = NULL;

	//initialize?
}

