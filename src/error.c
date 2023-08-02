/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:26:35 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/02 17:32:28 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	write(2, "\033[31mcommand not found\n", 24);
	exit(127);
}

void	exit_error(const char *msg)
{
	ft_printf("\033[31mERROR - %s\e[0m", msg);
	exit(EXIT_FAILURE);
}

void	clean_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}