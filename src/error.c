/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:26:35 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/31 13:52:51 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	printf("\033[31mERROR: %s - \n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	exit_error(const char *msg)
{
	printf("\033[31mERROR - %s\e[0m", msg);
	exit(EXIT_FAILURE);
}
