/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:34:28 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 09:33:28 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_path(char *mycmd, char **env)
{
	char	*cmd_path;
	char	*temp;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(&env[i][5], ':');
	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp, mycmd);
		free(temp);
		if (access(cmd_path, F_OK) != -1)
		{
			ft_clean(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_clean(paths);
	return (0);
}

void	run(char *arg, char **env)
{
	char	**mycmd;
	char	*path_cmd;

	mycmd = ft_split(arg, ' ');
	if (ft_strchr(mycmd[0], '/'))
	{
		path_cmd = mycmd[0];
		if (execve(path_cmd, mycmd, env) == -1)
		{
			ft_clean(mycmd);
			error();
		}
	}
	else
		path_cmd = check_path(mycmd[0], env);
	if (path_cmd == 0 || execve(path_cmd, mycmd, env) == -1)
	{
		ft_clean(mycmd);
		free(path_cmd);
		if (path_cmd == 0)
			error_cmd();
		else
			error();
	}
}

void	child_process_1(char **av, int *fd, char **env)
{
	int	input;

	if (close(fd[0]) == -1)
		error();
	input = open(av[1], O_RDONLY, 0777);
	if (input < 0)
		error();
	if (fd[1] != STDOUT_FILENO)
	{
		if (dup2(input, STDIN_FILENO) == -1)
			error();
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error();
		if (close(input) == -1)
			error();
		run(av[2], env);
	}
}

void	child_process_2(char **av, int *fd, char **env)
{
	int	output;

	if (close(fd[1]) == -1)
		error();
	output = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (output < 0)
		error();
	if (fd[0] != STDIN_FILENO)
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error();
		if (dup2(output, STDOUT_FILENO) == -1)
			error();
		if (close(output) == -1)
			error();
		run(av[3], env);
	}
}
