/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 16:16:25 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/21 17:12:27 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    kiddo_1(t_pipex *pepe)
{
    pepe->infile = open(pepe->av[1], O_RDONLY);
    if (pepe->infile == -1)
        error_brexit("can't open infile", EXIT_FAILURE);
        
}

int    pipex(t_pipex *pepe)
{
    int status;

    if (pipe(pepe->pipefd) < 0)
        error_brexit("pipe", errno);
    pepe->kiddo1 = fork();
    if (pepe->kiddo1 == -1)
        error_brexit("fork1", errno);
    if (pepe->kiddo1 == 0)
        //child_cmd_1(pepe);
    pepe->kiddo2 = fork();
    if (pepe->kiddo2 == -1)
        error_brexit("fork2", errno);
    if (pepe->kiddo2 == 0)
        //child_cmd_2(pepe);
    close(pepe->pipefd[READ]);
    close(pepe->pipefd[WRITE]);
    waitpid(pepe->kiddo1, NULL, 0);
    waitpid(pepe->kiddo2, &status, 0);
    close(pepe->infile); //nodig?
    close(pepe->outfile); //nodig?
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
    return (EXIT_SUCCESS);
}
