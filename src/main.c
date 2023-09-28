/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:21:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/22 16:13:15 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void *close_program(t_pipex *pepe)
{
    int status;
    //status 1 + 2, want moet status child 1 gecheckt worden?

    close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
    waitpid(pepe->kiddo1, NULL, 0);
    waitpid(pepe->kiddo2, &status, 0);
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
    exit(EXIT_SUCCESS);
}

int main(int ac, char **av, char **envp)
{
    t_pipex *pepe;

    if (ac != 5)
        error_brexit("give 4 arguments bozo", errno);
    pepe = init_bruv(av, envp);
    if (pipe(pepe->pipefd) < 0)
        error_brexit("pipe error", errno);
    pepe->kiddo1 = fork();
    if (pepe->kiddo1 == -1)
        error_brexit("fork1", errno);
    if (pepe->kiddo1 == 0)
        kiddo_1_write(pepe);
    pepe->kiddo2 = fork();
    if (pepe->kiddo2 == -1)
        error_brexit("fork2", errno);
    if (pepe->kiddo2 == 0)
        kiddo_2_read(pepe);
    close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
    close_program(pepe);
}


//strncmp + strjoin + split, needed functions
//parsing: loop through the env (strncmp first 5 PATH=),
//afterwards loop through the string and split every :
//open / read infile
//access cmd = check accessiblity of a file
//execute the command

//env to check enviroment paths

//./pipex Makefile "ps aux" "grep pipex" outfile
//./pipex Makefile "ps aux" "lsof -c pipex" outfile (checkt welke fd's openstaan)