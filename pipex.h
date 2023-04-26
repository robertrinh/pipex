/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/26 17:28:42 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* close */
# include <unistd.h>
# include <stdlib.h>
/* perror */
# include <stdio.h>
# include <string.h>
/* waitpid, wait */
# include <sys/wait.h>

/* open */
#include <fcntl.h>

/* libft */
#include "libft/libft.h"

typedef struct s_pipex
{
	char	**path;
	char	**cmd;
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	kiddo;
}	t_pipex;

int		main(int argc, char *argv[], char *envp[]);
void	pipex(t_pipex pepe, int argc, char *argv[], char *envp[]);
void	error_handler(char *error_msg);
t_pipex	*pepe_init(void);
void	kiddo_process(t_pipex pepe, char *argv, char *envp[]);
char    **get_path(char *envp[], t_pipex pepe);
char    **seek_path(char *envp[]);

#endif