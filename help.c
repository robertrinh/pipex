/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 11:42:10 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/04/26 16:43:45 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handler(char *error_msg)
{
	// free(pepe);
	perror(error_msg);
	exit(EXIT_FAILURE);
}

// t_pipex	*pepe_init(void)
// {
// 	t_pipex *pepe;
// 	pepe = ft_calloc(sizeof(t_pipex), 1);
// 	//je kan waardes nog erinzetten
// 	//ook voor argc/argv als je dat nog wilt gebruiken
// 	return (pepe);
// }

