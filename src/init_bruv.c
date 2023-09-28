/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 16:02:07 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/28 17:54:10 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex *init_bruv(char **av, char **envp)
{
    t_pipex *pepe;

    pepe = ft_calloc(1, sizeof(t_pipex));
    pepe->av = av;
    pepe->envp = envp;
    pepe->path = get_path(envp, pepe);
    pepe->infile = NULL;
    pepe->outfile = NULL; 
    return (pepe);
}
