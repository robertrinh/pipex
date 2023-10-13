/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:21:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/13 14:14:55 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	leaks_check(void)
{
	system("leaks pipex");
}

static void	*close_program(t_pipex *pepe)
{
	int	kidstatus1;
	int	kidstatus2;

	close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
	waitpid(pepe->kiddo1, &kidstatus1, 0);
	waitpid(pepe->kiddo2, &kidstatus2, 0);
	// atexit(&leaks_check); //delete
	if (WIFEXITED(kidstatus1))
		exit(WEXITSTATUS(kidstatus1)); //kan weg. checkt alleen status van laatste kid
	if (WIFEXITED(kidstatus2))
		exit(WEXITSTATUS(kidstatus2));
	exit(EXIT_SUCCESS);
	// free je shit
	// return (WEXITSTATUS kiddo2)
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pepe;

	if (ac != 5)
	{
		errno = EINVAL;
		error_brexit("give 4 arguments mate", EINVAL);
	}
	pepe = init_bruv(av, envp); //caloc protect add
	if (pipe(pepe->pipefd) < 0)
		error_brexit("pipe error", errno);
	pepe->kiddo1 = fork();
	if (pepe->kiddo1 == -1)
		error_brexit("fork1", errno); 
	if (pepe->kiddo1 == 0)
		kiddo_1_write(pepe, envp);
	pepe->kiddo2 = fork();
	if (pepe->kiddo2 == -1)
		error_brexit("fork2", errno); // waitpid kiddo1 implementen + close pipes in case of failure
	if (pepe->kiddo2 == 0)
		kiddo_2_read(pepe, envp);
	close_program(pepe);
}

//things to consider:
//error handling
//empty commands?
//incorrecte commands: command not found

//fork -> sla meteen op in struct. child process krijgt pid0. main process heeft al pid. 
//meteen opslaan in struct, krijgen beide parent/child process krijgen 0 als PID.
//--> volgorde van opslaan is anders op MAC. MAC doet apart opslaan, op linux anders. 
//daarom failt execve --> voor minishil
//voor fix-> pid op stack opslaan. Na je if statement pid opslaan in de struct (mbt startprocess)

//./pipex Makefile "ps aux" "grep pipex" outfile
//./pipex Makefile "ps aux" "lsof -c pipex" outfile 
//->(checkt welke fd's openstaan)