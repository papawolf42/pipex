/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:25:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/21 07:03:25 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_read_infile_execute(char **argv, char **envp, char **paths, int *fd)
{
	pid_t	pid;
	int		infile;
	char	**cmd;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		err_msg("open");
	cmd = ft_split(argv[2], ' ');
	if (cmd == NULL)
		err_msg("split");
	pid = fork();
	if (pid == -1)
		err_msg("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		return (execve(ft_find_path(paths, cmd[0]), cmd, envp));
	}
	close(infile);
	ft_free_split(cmd);
	return (0);
}

int	ft_execute_write_outfile(char **argv, char **envp, char **paths, int *fd)
{
	pid_t	pid;
	int		outfile;
	char	**cmd;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		err_msg("open");
	cmd = ft_split(argv[3], ' ');
	if (cmd == NULL)
		err_msg("split");
	pid = fork();
	if (pid == -1)
		err_msg("fork");
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		return (execve(ft_find_path(paths, cmd[0]), cmd, envp));
	}
	close(outfile);
	ft_free_split(cmd);
	return (0);
}

int	ft_execute_parellel(char **argv, char **envp, char **paths)
{
	int		fd[2];

	if (pipe(fd) == -1)
		err_msg("pipe");
	ft_read_infile_execute(argv, envp, paths, fd);
	ft_execute_write_outfile(argv, envp, paths, fd);
	close(fd[0]);
	close(fd[1]);
	while (wait(NULL) != -1)
	{
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc != 5)
		err_msg("Invalid input format");
	ft_open_infile(argv[1]);
	ft_open_outfile(argv[2]);
	paths = ft_get_paths(envp);
	if (paths == NULL)
		err_msg("malloc");
	ft_execute_parellel(argv, envp, paths);
	ft_free_split(paths);
	return (0);
}
