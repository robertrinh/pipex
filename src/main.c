/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:21:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/12 16:59:01 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	*close_program(t_pipex *pepe)
{
	int	kidstatus1;
	int	kidstatus2;

	close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
	waitpid(pepe->kiddo1, &kidstatus1, 0);
	waitpid(pepe->kiddo2, &kidstatus2, 0);
	if (WIFEXITED(kidstatus1))
		exit(WEXITSTATUS(kidstatus1));
	if (WIFEXITED(kidstatus2))
		exit(WEXITSTATUS(kidstatus2));
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pepe;

	if (ac != 5)
		error_brexit("give 4 arguments bozo", errno);
	pepe = init_bruv(av, envp);
	if (pipe(pepe->pipefd) < 0)
		error_brexit("pipe error", errno);
	pepe->kiddo1 = fork();
	if (pepe->kiddo1 == -1)
		error_brexit("fork1", errno);
	if (pepe->kiddo1 == 0)
		kiddo_1_write(pepe, envp);
	pepe->kiddo2 = fork();
	if (pepe->kiddo2 == -1)
		error_brexit("fork2", errno);
	if (pepe->kiddo2 == 0)
		kiddo_2_read(pepe, envp);
	close_program(pepe);
}

//things to consider:
//error handling
//empty commands?

//./pipex Makefile "ps aux" "grep pipex" outfile
//./pipex Makefile "ps aux" "lsof -c pipex" outfile 
//->(checkt welke fd's openstaan)