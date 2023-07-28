/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:28 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/28 16:31:41 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// char	*check_path(char *mycmd, char **env)
// {
// 	char	*cmd_path;
// 	char	*temp;
// 	char	**paths;
// 	int		i;

// 	i = 0;
// 	while (ft_strnstr(env[i], "PATH=", 5) == 0)
// 		i++;
// 	paths = ft_split(env[i], ':');
// 	i = 0;
// 	while (paths[i] != 0)
// 	{
// 		temp = ft_strjoin(paths[i], "/");
// 		cmd_path = ft_strjoin(temp, mycmd);
// 		free(temp);
// 		if (access(cmd_path, F_OK) == 0)
// 			return (cmd_path);
// 		free(cmd_path);
// 		i++;
// 	}
// 	i = -1;
// 	while (paths[++i])
// 		free(paths[i]);
// 	free(paths);
// 	return (0);
// }

// void	run(char *arg, char **env)
// {
// 	char	**mycmd;
// 	char	*path_cmd;
// 	int		i;
// 	printf("entrou run mesmo\n");
// 	i = 0;
// 	mycmd = ft_split(arg, ' ');
// 	path_cmd = check_path(mycmd[0], env);
// 	if (path_cmd == 0)	
// 	{
// 		while (mycmd[i])
// 		{
// 			free(mycmd[i]);
// 			i++;
// 		}	
// 		free(mycmd);
// 		error("path_cmd");
// 	}
// 	if (execve(path_cmd, mycmd, env) == -1)
// 		error("execve");
// }

void	child_process_1(char **av, int *fd, char **env)
{
	int	input;
	(void)env;
	
	printf("entrou child1\n");
	if (close(fd[0]) == -1)
		error("close fd[0]");
	//input = open(av[1], O_RDONLY, 0777);
	// if (input < 0)
	// 	error("open fd\n");
//	printf("abriu\n");
	if (fd[1] != STDOUT_FILENO)
	{
		printf("ate aqui ok\n");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error("dup2 fd[1]");
		printf("primeira vez ok\n");
		if (close(fd[1]) == -1)
			error("close fd[1]");
		printf("segunda vez ok\n");
		printf("child1 vai chamar o run\n");
	//	run(av[2], env);
		int a = open("teste.txt", O_WRONLY | O_CREAT | O_TRUNC);
		write(a, "teste", 5);
		close(a);
	}
}

void	child_process_2(char **av, int *fd, char **env)
{
	int	input;
	(void)env;
	printf("entrou child2\n");

	if (close(fd[1]) == -1)
		error("close fd[1]");
	// input = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	// if (input < 0)
	// 	error("open fd\n");
	if (fd[0] != STDIN_FILENO)
	{
		printf("child 2 ate aqui ok\n");
		if (dup2(fd[0], STDIN_FILENO) < 0)
			error("dup2 fd[1]");
		printf("child 2 sem erro\n");
		if (close(fd[0]) == -1)
			error("close fd[1]");
		printf("child2 chama run\n");
	//	run(av[3], env);
	}
}
