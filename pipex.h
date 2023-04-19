/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/19 18:11:31 by qtrinh        ########   odam.nl         */
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
	int		fd1;
	int		fd2;
	pid_t	kiddo;
}	t_pipex;

// void	pipex(int f1, int f2);
int		main(int argc, char *argv[], char *envp[]);
void	pipex(int argc, char *argv[], char *envp[]);
// int		main(void);
void	error_handler(char *error_msg, t_pipex *pipex);
t_pipex	*pepe_init(void);
void	kiddo1_process(t_pipex *pipex, char *argv[], char *envp[]);

#endif