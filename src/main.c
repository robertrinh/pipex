/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:21:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/13 16:59:43 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	leaks_check(void)
{
	system("leaks pipex");
}

/**
 * @brief closes parent process pipes + waits for childprocesses.
 * @brief WIFEXITED checks of child process ended normally.
 * @param t_pipex struct which contains pid of child processes
 * @details pipes only can save 1 exitstatus of a childprocess -> so last one
 * @return exitcode specified by child process (WEXITSTATUS)
*/
static void	*close_program(t_pipex *pepe)
{
	int	kidstatus1;
	int	kidstatus2;

	close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
	waitpid(pepe->kiddo1, &kidstatus1, 0);
	waitpid(pepe->kiddo2, &kidstatus2, 0);
	atexit(&leaks_check); //delete
	if (WIFEXITED(kidstatus2))
		exit(WEXITSTATUS(kidstatus2));
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pepe;

	if (ac != 5)
		error_arg();
	pepe = init_bruv(av, envp);
	if (pipe(pepe->pipefd) < 0)
		error_brexit("pipe error", errno);
	pepe->kiddo1 = fork();
	if (pepe->kiddo1 == -1)
	{
		close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
		error_brexit("fork1", errno);
	}
	if (pepe->kiddo1 == 0)
		kiddo_1_write(pepe, envp);
	pepe->kiddo2 = fork();
	if (pepe->kiddo2 == -1)
	{
		close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
		waitpid(pepe->kiddo1, NULL, 0);
		error_brexit("fork2", errno);
	}
	if (pepe->kiddo2 == 0)
		kiddo_2_read(pepe, envp);
	close_program(pepe);
}

//VOOR MINISHELL (en why it doesnt work on linux)
//fork -> sla meteen op in struct. child process krijgt pid0. main process heeft al pid. 
//meteen opslaan in struct, krijgen beide parent/child process krijgen 0 als PID.
//--> volgorde van opslaan is anders op MAC. MAC doet apart opslaan, op linux anders. 
//daarom failt execve --> voor minishil
//voor fix-> pid op stack opslaan. Na je if statement pid opslaan in de struct (mbt startprocess)

//./pipex Makefile "ps aux" "grep pipex" outfile
//./pipex Makefile "ps aux" "lsof -c pipex" outfile 
//->(checkt welke fd's openstaan)