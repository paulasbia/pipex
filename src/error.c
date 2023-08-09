/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:26:35 by pde-souz          #+#    #+#             */
/*   Updated: 2023/08/09 09:34:12 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_cmd(void)
{
	write(2, "\033[31mcommand not found\n\e[0m", 28);
	exit(127);
}

void	error(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

void	exit_error(const char *msg)
{
	ft_printf("\033[31mERROR - %s\e[0m", msg);
	exit(EXIT_FAILURE);
}

void	ft_clean(char **to_clean)
{
	int	i;

	i = -1;
	while (to_clean[++i])
		free(to_clean[i]);
	free(to_clean);
}
