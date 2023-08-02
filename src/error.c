/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:26:35 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/02 16:27:54 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	exit_error(const char *msg)
{
	printf("\033[31mERROR - %s\e[0m", msg);
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