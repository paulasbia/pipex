/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:11:53 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/15 12:25:54 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "../libft/libft.h"
# include <errno.h> 
# include <fcntl.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <sys/wait.h> 
# include <unistd.h> 
# include <string.h>

void    error(const char *fName);
void    exitError(const char *msg);

#endif