/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 15:26:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/13 16:05:55 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	*init_bruv(char **av, char **envp)
{
	t_pipex	*pepe;

	pepe = ft_calloc(1, sizeof(t_pipex));
	if (!pepe)
		return (NULL);
	pepe->av = av;
	pepe->path = get_path(envp);
	return (pepe);
}

void	close_pipes(int fd1, int fd2)
{
	if (fd1 || fd2)
	{
		if (close(fd1) < 0)
			perror("close error");
		if (close(fd2) < 0)
			perror("close error");
	}
}

void	check_nullspace(char *str)
{
	if (str[0] == '\0')
		error_command(str);
	if (str[0] == ' ')
		error_command(str);
}
