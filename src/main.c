/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:59:56 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/28 16:17:32 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	int		status;
	pid_t	child_pid1;
	pid_t	child_pid2;

	(void)ac;
	// if (ac != 5)
	// 	exit_error("Five arguments required.\n");
	if (pipe(fd) < 0)
		error("PIPE");
	child_pid1 = fork();
	if (child_pid1 < 0)
		error("fork child1");
	if (child_pid1 == 0)
		child_process_1(av, fd, env);
	child_pid2 = fork();
	if (child_pid2 < 0)
		error("fork child2");
	if (child_pid2 == 0)
		child_process_2(av, fd, env);
	// close(fd[0]);
	// close(fd[1]);
	waitpid(child_pid1, &status, 0);
	waitpid(child_pid2, &status, 0);
	printf("saindo do programa\n");
	return (0);
}
