/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:36:44 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/01 12:49:23 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		status;
	pid_t	child_pid1;
	pid_t	child_pid2;

	if (ac != 5)
		exit_error("Five arguments required.\n");
	if (pipe(fd) < 0)
		error();
	child_pid1 = fork();
	if (child_pid1 < 0)
		error();
	if (child_pid1 == 0)
		child_process_1(av, fd, env);
	child_pid2 = fork();
	if (child_pid2 < 0)
		error();
	if (child_pid2 == 0)
		child_process_2(av, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(child_pid1, &status, 0);
	waitpid(child_pid2, &status, 0);
	return (WEXITSTATUS(status));
}
