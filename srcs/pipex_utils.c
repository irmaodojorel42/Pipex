/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:42:11 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 19:25:11 by ceribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_split_free(char **split_result)
{
	int	i;

	if (split_result)
	{
		i = -1;
		while (split_result[++i])
			free(split_result[i]);
		free(split_result);
	}
}

char	*check_path(char **path, char *cmd)
{
	int		i;
	char	*cmd_path;
	char	*temp;

	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK) != -1)
		{
			ft_split_free(path);
			return (cmd_path);
		}
		free(cmd_path);
	}
	write(2, "Error, Command invalid\n", 24);
	return (NULL);
}

char	*command(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*cmd_path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = ft_split(&env[i][5], ':');
	cmd_path = check_path(path, cmd);
	ft_split_free(path);
	return (cmd_path);
}

void	run(char *cmd, char **env)
{
	char	**list_cmd;
	char	*path;

	list_cmd = ft_split(cmd, ' ');
	cmd = list_cmd[0];
	if (!env)
		error();
	path = command(cmd, env);
	if (!path || execve(path, list_cmd, env) == -1)
	{
		ft_split_free(list_cmd);
		if (path)
			error();
		else
			exit(write(2, "Error\n", 7));
	}
	ft_split_free(list_cmd);
}

void	process(char **argv, int *pipefd, char **env, int process_nbr)
{
	int	file1;
	int	file2;

	if (process_nbr == 1)
	{
		file1 = open(argv[1], O_RDONLY);
		if (file1 < 0)
			cleanup_error(pipefd, file1);
		close(pipefd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		run(argv[2], env);
	}
	else
	{
		file2 = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (file2 < 0)
			cleanup_error(pipefd, file2);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		dup2(file2, STDOUT_FILENO);
		run(argv[3], env);
	}
}
