/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:14 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/03/16 17:04:43 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_kiddo(t_pipex *pipex, char *argv[], char *envp[])
{
	pid_t	kiddo1;
	pid_t	kiddo2;
	
	kiddo1 = fork();
	if (kiddo1 == -1)
		error_message();
	if (kiddo1 == 0)
	{
		if (dup2(pipex->fd1, STDIN_FILENO) == -1)
		(
			perror("dup2 kiddo1 error");
			exit(EXIT_FAILURE);
		)
		close(pipex->fd[0]);
		
	}
	
}

void	second_kiddo(t_pipex *pipex, char *argv[], char *envp[])
{
	pid_t	kiddo2;
	
	kiddo2 = fork();
	if (kiddo2 == -1)
		error_message();
}

int	main(int argc, char *argv[], char *envp[]) //KEEP IT SHORT (je main)
{
	t_pipex *pipex;

	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (!pipex)
		return (NULL);
	if (argc != 5)
		return (ft_printf("error, wrong amount of arguments")); //geeft geen ERRNO aan
	if (pipe(pipex->fd) == -1)
		error_message();
	//error management mbt no commands in pipex
	return (EXIT_SUCCESS);	
}

// int	main(void)
// {
// 	ft_printf("LIBFT WORKS\n");
// 	return (0);
// }
