/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 15:08:17 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/03/16 17:04:05 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
/* waitpid, wait */
# include <sys/wait.h>

/* libft */
#include "libft/libft.h"

typedef struct s_pipex
{
	char	**argv;
	char	**envp;
	int		fd[2];
	int		fd1;
	int		fd2;
}	t_pipex;



// void	pipex(int f1, int f2);
int		main(int args, char *argv[], char *envp[]);
// int		main(void);
void	error_message(void);

#endif