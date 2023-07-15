/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:26:35 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/15 14:56:30 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(const char *fName)
{
	printf("ERROR - %s - %s\n", fName, strerror(errno));
	exit(EXIT_FAILURE);
}

void	exit_error(const char *msg)
{
	printf("ERROR - %s\n", msg);
	exit(EXIT_FAILURE);
}
