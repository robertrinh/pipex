/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 15:21:24 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/21 16:39:51 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int ac, char **av, char **envp)
{
    // t_pipex *pepe;

    if (ac != 5)
        error_brexit("give 4 arguments bozo", STDERR_FILENO);
    else
    {
        init_bruv(av, envp);
        //pipex(pepe); //fix
        //free_pipex(pepe); //fix
        return (EXIT_SUCCESS);
    }
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