/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:42:14 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 20:42:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(void)
{
	//caso o run nao function limpar todos os ** ou * ou **** execve quando da erro nao apaga a memoria
	perror("error");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;

	if (argc != 5)
		exit(write(2, "Error, insert 5 arguments\n", 27));
	if (pipe(pipefd) == -1)
		error();
	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
		process(argv, pipefd, env, 1);
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		process(argv, pipefd, env, 2);
	close(pipefd[0]);
	waitpid(-1, &status, 0);
	return (WEXITSTATUS(status));
}

