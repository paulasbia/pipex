/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:59:56 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/15 12:25:24 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main (int ac, char **av)
{
    int fd[2];
    (void)ac;
    (void)av;
    
    if (ac < 5)
        exitError("Five arguments required.\n");
    if (pipe(fd) < 0)
        error("PIPE");
    if (open("teste", O_RDONLY) < 0)
        error("OPEN");
    return (0);
}