/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:59:56 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/15 15:04:38 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av)
{
	int		fd[2];
	pid_t	child_pid1;
	pid_t	child_pid2;

	if (ac != 5)
		exit_error("Five arguments required.\n");
	if (pipe(fd) < 0)
		error("PIPE");
	child_pid1 = fork();
	if (child_pid1 < 0)
		error("fork child1");
	if (child_pid1 == 0)
		child_process(av, fd);
	child_pid2 = fork();
	if (child_pid2 < 0)
		error("fork child2");
	if (child_pid2 == 0)
		child_process(av, fd);
	wait(NULL);
	parent_process();
	return (0);
}
