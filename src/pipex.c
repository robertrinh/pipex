/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 16:16:25 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/28 18:11:28 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    kiddo_1_write(t_pipex *pepe, char **envp, char *cmd)
{
    pepe->infile = open(pepe->av[1], O_RDONLY);
    if (pepe->infile == -1)
        error_brexit("can't open infile", errno);
	if (dup2(pepe->pipefd[WRITE], STDOUT_FILENO) == -1)
		error_brexit("DUP2 ERROR", errno);;
    if (dup2(pepe->infile, STDIN_FILENO) == -1)
		error_brexit("DUP2 ERROR", errno);
    close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
    close(pepe->infile);
    run_cmd(envp, pepe, 2);
}

void   kiddo_2_read(t_pipex *pepe, char **envp, char *cmd)
{
    pepe->outfile = open(pepe->av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (pepe->outfile == -1)
        error_brexit("can't open outfile", errno);
    if (dup2(pepe->pipefd[READ], STDIN_FILENO) == -1)
        error_brexit("DUP2 ERROR", errno);
    if (dup2(pepe->outfile, STDOUT_FILENO) == -1)
        error_brexit("DUP2 ERROR", errno);
    close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
    close(pepe->outfile);
    run_cmd(envp, pepe, 3);
}

void    run_cmd(char **envp, t_pipex *pepe, int cmdlen)
{
    char    *cmd;
    char    **cmd_args;

    cmd_args = ft_split(pepe->av[cmdlen], ' ');
    cmd = correct_path_cmd(envp, pepe, cmd);
    if (cmd && access(cmd, X_OK) == -1)
        error_access(cmd);
    if (execve(cmd, cmd_args, envp) == -1)
        error_brexit("iets met space", errno);
}


//after dup2, you have to execute and find the command
//find path
//read envp to check for path
//check if cmd can be run in of the paths
//Don't forget to check absolute paths to commands (e.g. /usr/bin/wc).

// int    pipex(t_pipex *pepe)
// {
//     int status;

//     if (pipe(pepe->pipefd) < 0)
//         error_brexit("pipe error", errno);
//     pepe->kiddo1 = fork();
//     if (pepe->kiddo1 == -1)
//         error_brexit("fork1", errno);
//     if (pepe->kiddo1 == 0)
//         kiddo_1(pepe);
//     pepe->kiddo2 = fork();
//     if (pepe->kiddo2 == -1)
//         error_brexit("fork2", errno);
//     if (pepe->kiddo2 == 0)
//         kiddo_2(pepe);
//     close(pepe->pipefd[READ]);
//     close(pepe->pipefd[WRITE]);
//     waitpid(pepe->kiddo1, &status, 0);
//     waitpid(pepe->kiddo2, &status, 0);
//     // close(pepe->infile); //nodig?
//     // close(pepe->outfile); //nodig?
//     if (WIFEXITED(status))
//         exit(WEXITSTATUS(status));
//     return (EXIT_SUCCESS);
// }
