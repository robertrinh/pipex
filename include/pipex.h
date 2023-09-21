/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/21 17:05:52 by robertrinh    ########   odam.nl         */
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
# include <sys/errno.h>

/* open */
#include <fcntl.h>

/* libft */
#include "../libft/include/libft.h"

typedef struct s_pipex
{
	char	**path;
	char	**envp;
	char	**av;
	int		path_f;
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	kiddo1;
	pid_t	kiddo2;
}	t_pipex;

# define READ 0
# define WRITE 1

t_pipex	init_bruv(char **av, char **envp);
void    error_brexit(char *str, int error);
int	pipex(t_pipex *pepe);

void	error_handler(char *error_msg);
t_pipex	*pepe_init(void);
void	kiddo_process(t_pipex pepe, char *argv, char *envp[]);
char    **get_path(char *envp[], t_pipex pepe);
char    **seek_path(char *envp[]);

#endif