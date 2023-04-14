/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:14 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/14 16:42:34 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kiddo1_process(t_pipex *pipex, char *argv[], char *envp[])
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 == -1)
		error_handler("ERROR, no input file", pipex);
	if (dup2(pipex->fd1, STDIN_FILENO) == -1)
		error_handler("DUP2 ERROR", pipex);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		error_handler("DUP2 ERROR", pipex);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	
	
}


void	pipex(int argc, char *argv[], char *envp[])
{
	t_pipex *pipex;
	pid_t	kiddo1;
	pid_t	kiddo2;

	pepe_init();
	if (argc != 5)
		error_handler("error, wrong amount of arguments", pipex); //geeft geen ERRNO aan
	if (pipe(pipex->pipefd) == -1)
		error_handler("pipe error", pipex);
	kiddo1 = fork();
	if (kiddo1 == -1)
		error_handler("fork error", pipex);
	if (kiddo1 == 0)
		kiddo1_process(pipex->pipefd, argv, envp);
	// kiddo2 = fork(); fix 1 maar eerst
	// if (kiddo2 == -1)
	// 	error_handler("fork2 error", pipex);
	// if (kiddo2 == 0)
	// 	kiddo2_process(pipex->pipefd, argv, envp);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]); //remains open even when duped, drm close
	waitpid(kiddo1, NULL, 0);
	// waitpid(kiddo2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	pipex(argc,argv,envp);
	return (0);	
}
