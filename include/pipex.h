/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/09/28 18:04:02 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* close */
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

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
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	kiddo1;
	pid_t	kiddo2;
}	t_pipex;

# define READ 0
# define WRITE 1

t_pipex	*init_bruv(char **av, char **envp);
void    error_brexit(char *str, int error);
int	pipex(t_pipex *pepe);
void    close_pipes(int fd_one, int fd_two);
char	**get_path(char **envp, t_pipex *pepe);
char	*correct_path_cmd(char **envp, t_pipex *pepe, char *cmd);

void    error_path(char *cmd);
void	error_access(char *path);

void	kiddo_1_write(t_pipex *pepe, char **envp, char *cmd);
void	kiddo_2_read(t_pipex *pepe, char **envp, char *cmd);
// void	error_handler(char *error_msg);
// t_pipex	*pepe_init(void);
// void	kiddo_process(t_pipex pepe, char *argv, char *envp[]);
// char    **get_path(char *envp[], t_pipex pepe);
// char    **seek_path(char *envp[]);

#endif