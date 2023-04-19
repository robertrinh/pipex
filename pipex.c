/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pepe.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:14 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/19 16:12:45 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	kiddo_process(t_pipex *pepe, char *argv[], char *envp[])
{
	pepe->fd1 = open(argv[1], O_RDONLY);
	if (pepe->fd1 == -1)
		error_handler("ERROR, no input file", pepe);
	if (dup2(pepe->fd1, STDIN_FILENO) == -1)
		error_handler("DUP2 ERROR", pepe);
	if (dup2(pepe->pipefd[1], STDOUT_FILENO) == -1)
		error_handler("DUP2 ERROR", pepe);
	close(pepe->pipefd[0]);
	close(pepe->pipefd[1]);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	t_pipex *pepe;
	// pid_t	kiddo1;
	// pid_t	kiddo2;

	pepe_init();
	if (pipe(pepe->pipefd) == -1)
		error_handler("pipe error", pepe);
	pepe->kiddo = fork();
	if (pepe->kiddo == -1)
		error_handler("fork error", pepe);
	if (pepe->kiddo == 0)
		kiddo1_process(pepe->pipefd, argv, envp);
	// kiddo2 = fork(); fix 1 maar eerst
	// if (kiddo2 == -1)
	// 	error_handler("fork2 error", pepe);
	// if (kiddo2 == 0)
	// 	kiddo2_process(pepe->pipefd, argv, envp);
	close(pepe->pipefd[0]);
	close(pepe->pipefd[1]); //remains open even when duped, drm close
	// waitpid(pepe->kiddo, NULL, 0);
	// waitpid(kiddo2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{	
	t_pipex *pepe;
	
	if (argc != 5)
		error_handler("error, wrong amount of arguments", pepe); //geeft geen ERRNO aan
	//pepe->path = parsing(envp, pepe);
	pipex(argc,argv,envp);
	return (0);	
}


//strncmp + strjoin + split, needed functions
//parsing: loop through the env (strncmp first 5 PATH=), afterwards loop through the string and split every :
//open / read infile
//access cmd = check accessiblity of a file  
//execute the command

//env to check enviroment paths