/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:42:17 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 20:42:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

/*********************BIBLIOTECAS*********************/

# include "../mylibft/libft.h"
# include <errno.h> /*biblioteca pra erro*/
# include <fcntl.h> /*para dar open e close*/
# include <stdio.h> /*pipe*/
# include <stdlib.h> /*env*/
# include <sys/wait.h> /*biblioteca pro fork, waitpid*/
# include <unistd.h> /*write, dup2*/

/*********************FUNCTIONS*********************/

void	error(void);
char	*check_path(char **path, char *cmd);
char	*command(char *cmd, char **env);
void	run(char *cmd, char **env);
void	process(char **argv, int *pipefd, char **env, int process_nbr);

#endif