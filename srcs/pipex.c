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
	perror("error");
	exit(EXIT_FAILURE);
}

void cleanup(int *pipefd, int file1, int file2) 
{
    close(pipefd[0]);
    close(pipefd[1]);
    if (file1 >= 0)
		close(file1);
    if (file2 >= 0)
		close(file2);
}

int	main(int argc, char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;
	int		file1;
	int		file2;

	file1 = -1;
	file2 = -1;

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
	waitpid(-1, &status, 0);
	cleanup(pipefd, file1, file2);
	return (WEXITSTATUS(status));
}

