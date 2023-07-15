/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:28 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/15 15:02:28 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, int *fd)
{
	int	input;

	if (close(fd[0]) == -1)
		error("close fd[0]");
	input = open(av[1], O_RDONLY, 077);
	if (input < 0)
		error("open fd\n");
	if (fd[1] != STDOUT_FILENO)
	{
		if (dup2(fd[1], STDOUT_FILENO) < 0)
			error("dup2 fd[1]");
		if (close(fd[1]) == -1)
			error("close fd[1]");
	}
}
