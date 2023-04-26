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

void	kiddo_process(t_pipex pepe, char *argv, char *envp[])
{
	char	*str;
	int		i;

	i = 0;
	pepe.cmd = ft_split(argv, ' ');
	if (access(pepe.cmd[0], X_OK) == 0)
		execve(pepe.cmd[0], pepe.cmd, envp);
	while (pepe.path[i])
	{
		str = ft_strjoin(pepe.path[i], pepe.cmd[0]);
		if (access(str, X_OK) == 0)
			execve(str, pepe.cmd, envp);
		free (str);
		i++;
	}
	exit (127);
}
	//kiddo_process
	// pepe->infile = open(argv[1], O_RDONLY);
	// if (pepe->infile == -1)
	// 	error_handler("ERROR, no input file", pepe);
	// if (dup2(pepe->infile, STDIN_FILENO) == -1)
	// 	error_handler("DUP2 ERROR", pepe);
	// if (dup2(pepe->pipefd[1], STDOUT_FILENO) == -1)
	// 	error_handler("DUP2 ERROR", pepe);
	//STAAT IN NIEUWE FUNCTIE

void	pipex(t_pipex pepe, int argc, char *argv[], char *envp[])
{
	int 	i;

	i = 2;
	while (i <= argc - 3)
	{
		if (pipe(pepe.pipefd) < 0)
			error_handler("pipe error");
		pepe.kiddo = fork();
		if (pepe.kiddo < 0)
			error_handler("fork error");
		if (pepe.kiddo == 0)
		{
			dup2(pepe.pipefd[1], STDOUT_FILENO);
			close(pepe.pipefd[0]);
			kiddo_process(pepe, argv[i], envp);
		}
		else
		{
			dup2(pepe.pipefd[0], STDIN_FILENO);
			close(pepe.pipefd[1]);
		}
		i++;
	}
	kiddo_process(pepe, argv[i], envp);
}
	// kiddo2 = fork(); fix 1 maar eerst
	// if (kiddo2 == -1)
	// 	error_handler("fork2 error", pepe);
	// if (kiddo2 == 0)
	// 	kiddo2_process(pepe->pipefd, argv, envp);
	//close(pepe->pipefd[0]);
	//close(pepe->pipefd[1]); //remains open even when duped, drm close
	// waitpid(pepe->kiddo, NULL, 0);
	// waitpid(kiddo2, NULL, 0);

// static void	in_n_outfile(int argc, char *argv[])
// {
// 	t_pipex	pepe;

// 	// pepe_init();
// 	pepe.infile = open(argv[1], O_RDONLY);
// 	if (pepe.infile < 0)
// 		error_handler("no infile");
// 	pepe.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	if (pepe. outfile < 0)
// 		error_handler("no outfile");
// 	if (dup2(pepe.infile, STDIN_FILENO) < 0)
// 		error_handler("DUP2 ERROR");
// 	if (dup2(pepe.outfile, STDOUT_FILENO) < 0)
// 		error_handler("DUP2 ERROR");
// }

int	main(int argc, char *argv[], char *envp[])
{	
	t_pipex pepe;

	if (argc != 5)
		return(ft_printf("give 4 arguments bozo\n"));
	pepe.infile = open(argv[1], O_RDONLY);
	pepe.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pepe.outfile < 0 || pepe.infile < 0)
		error_handler("no files");
	// if (!in_n_outfile(argc, argv))
	// 	return (1);
	pepe.path = seek_path(envp);
	pipex(pepe,argc,argv,envp);
	close(pepe.infile);
	close(pepe.outfile);
	exit(EXIT_SUCCESS);
}


//strncmp + strjoin + split, needed functions
//parsing: loop through the env (strncmp first 5 PATH=), afterwards loop through the string and split every :
//open / read infile
//access cmd = check accessiblity of a file  
//execute the command

//env to check enviroment paths