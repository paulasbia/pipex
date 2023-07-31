/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-souz <pde-souz@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:11:53 by pde-souz          #+#    #+#             */
/*   Updated: 2023/07/31 13:33:20 by pde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	error(void);
void	exit_error(const char *msg);
void	child_process_1(char **av, int *fd, char **env);
void	child_process_2(char **av, int *fd, char **env);
void	run(char *cmd, char **env);
char	*check_path(char *mycmd, char **env);


#endif