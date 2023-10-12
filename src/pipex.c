/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 16:16:25 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/10/06 17:32:48 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>

/**
 * @brief first childprocess; opens infile.
 * @brief closes pipes, runs command
 * @note dup2 copies infile to fd[0] (STDIN)
 * @note afterwards, dup2 also copies pipefd[1] to fd[1] (STDOUT)
 * @param t_pipex struct to access infile and pipefd for dup2
 * @param envp enviroment path given to run command
*/
void    kiddo_1_write(t_pipex *pepe, char **envp)
{
    pepe->infile = open(pepe->av[1], O_RDONLY);
    if (pepe->infile == -1)
        error_brexit("Can't open infile", errno);
    if (dup2(pepe->infile, STDIN_FILENO) == -1)
		error_brexit("DUP2 ERROR", errno);
	if (dup2(pepe->pipefd[WRITE], STDOUT_FILENO) == -1)
		error_brexit("DUP2 ERROR", errno);
    close_pipes(pepe->pipefd[READ], pepe->pipefd[WRITE]);
    close(pepe->infile);
    run_cmd(envp, pepe, 2);
}

/**
 * @brief second childprocess; opens outfile with rights.
 * @brief closes pipes, runs command
 * @note dup2 copies pipefd[0] to fd[0] (STDIN) from kiddo1
 * @note dup2 afterwards copies outfile to fd[1] (STDOUT)
 * @param t_pipex struct to access infile and pipefd for dup2
 * @param envp enviroment path given to run command
*/
void   kiddo_2_read(t_pipex *pepe, char **envp)
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

/**
 * @brief seeks command in path. checks if it exists.
 * @brief then check if it's executable
 * @note if execution succes, will return to parent process
 * @param envp enviroment path for the execution check
 * @param t_pipex struct which holds the av
 * @param cmdloc location of the cmdinput in av
*/
void    run_cmd(char **envp, t_pipex *pepe, int cmdloc)
{
    char    *cmd;
    char    **cmd_args;

    cmd_args = ft_split(pepe->av[cmdloc], ' ');
    cmd = correct_path_cmd(pepe, *cmd_args);
    if (cmd && access(cmd, X_OK) == -1)
        error_access(cmd);
    if (execve(cmd, cmd_args, envp) == -1)
        error_brexit("execve", errno);
}
