/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:28 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/31 10:31:14 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_path(char *mycmd, char **env)
{
	char	*cmd_path;
	char	*temp;
	char	**paths;
	int		i;

	printf("entrou check\n");
	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	printf("saiu do while com i %d\n", i);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp, mycmd);
		free(temp);
		if (access(cmd_path, F_OK) != -1)
		{
			printf("vai retornar \n");
			return (cmd_path);
		}
			
		free(cmd_path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	run(char *arg, char **env)
{
	char	**mycmd;
	char	*path_cmd;
	int		i;
	printf("entrou run mesmo\n");
	i = 0;
	mycmd = ft_split(arg, ' ');
	printf("mycmp eh %s\n", mycmd[0]);
	path_cmd = check_path(mycmd[0], env);
	if (path_cmd == 0)	
	{
		printf("deu ruim\n");
		while (mycmd[i])
		{
			free(mycmd[i]);
			i++;
		}	
		free(mycmd);
		error("path_cmd");
	}
	if (execve(path_cmd, mycmd, env) == -1)
		error("execve");
}

void	child_process_1(char **av, int *fd, char **env)
{
	int	input;
	
//	printf("entrou child1\n");
	if (close(fd[0]) == -1)
		error("close fd[0]");
	input = open(av[1], O_RDONLY, 0777);
	if (input < 0)
		error("open fd\n");
	if (fd[1] != STDOUT_FILENO)
	{
		dup2(input, STDIN_FILENO);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error("dup2 fd[1]");
		if (close(input) == -1)
			error("close input");
		run(av[2], env);
	}
}

void	child_process_2(char **av, int *fd, char **env)
{
	int	output;
	// printf("entrou child2\n");

	if (close(fd[1]) == -1)
		error("close fd[1]");
	output = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (output < 0)
		error("open fd\n");
	if (fd[0] != STDIN_FILENO)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			error("dup2 fd[1]");
		dup2(output, STDOUT_FILENO);
		if (close(output) == -1)
			error("close output");
		run(av[3], env);
	}
}
