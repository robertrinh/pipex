/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 15:26:27 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/09/22 15:37:02 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void    close_pipes(int fd_one, int fd_two)
{
    if (fd_one || fd_two)
    {
        if (close(fd_one) < 0)
            perror("close error");
        if (close(fd_two) < 0)
            perror("close error");
    }
}
