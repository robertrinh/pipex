/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/21 16:02:07 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/21 16:39:03 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex init_bruv(char **av, char **envp)
{
    t_pipex *pepe;

    pepe = ft_calloc(sizeof(t_pipex), 1);
    //return if fail?
    pepe->av = av;
    pepe->envp = envp;
    pepe->path_f = 0;
   // pepe->path = parse_env(pepe->envp); //maak parse env
    if (!pepe->path)
        pepe->path_f = -1;
    return (*pepe);
}
