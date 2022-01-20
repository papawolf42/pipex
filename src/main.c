/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:25:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/21 02:17:42 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **strs)
{
	int	i;
	
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	ft_open_infile(char *filename)
{
	if (access(filename, F_OK) != 0)
	{
		perror(filename);
		return (ERROR);
	}
	if (access(filename, R_OK) != 0)
	{
		perror(filename);
		return (ERROR);
	}
	return (0);
}

int	ft_open_outfile(char *filename)
{
	if (access(filename, F_OK) != 0)
		return (0);
	if (access(filename, W_OK) != 0)
	{
		perror(filename);
		return (ERROR);
	}
	return (0);
}

char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	// printf("find_paths!\n");
	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 5) == NULL))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		return (NULL);
	return (paths);
}

char	*ft_find_path(char **paths, char *cmd)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			return (NULL);
		path = ft_strjoin(temp, cmd);
		if (path == NULL)
			return (NULL);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			// printf("%d temp: %s !\n", i, temp);
			// printf("%d path: %s !\n", i, path);
			break;
		}
		free(path);
		i++;
	}
	printf("path: %s", path);
	return (path);
}

int	ft_read_infile_execute(char **argv, char **envp, char **paths, int *fd)
{
	pid_t	pid;
	int		infile;
	char	**cmd;
	int		rtn;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ERROR);
	cmd = ft_split(argv[2], ' ');
	if (cmd == NULL)
		return (ERROR);
	pid = fork();
	if (pid == -1)
		return (ERROR);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		// printf("cmd[0]: %s\n", cmd[0]);
		dup2(fd[1], STDOUT_FILENO);
		rtn = execve(ft_find_path(paths, cmd[0]), cmd, envp);
		close(fd[1]);
		printf("**rtn: %d", rtn);
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
	int		rtn;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (ERROR);
	cmd = ft_split(argv[3], ' ');
	if (cmd == NULL)
		return (ERROR);
	pid = fork();
	if (pid == -1)
		return (ERROR);
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		rtn = execve(ft_find_path(paths, cmd[0]), cmd, envp);
		close(fd[0]);
		printf("**rtn: %d", rtn);
	}
	close(outfile);
	ft_free_split(cmd);
	return (0);
}

int	ft_execute_parellel(char **argv, char **envp, char **paths)
{
	int		fd[2];

	if (pipe(fd) == -1)
		return (err_msg("pipe"));
	ft_read_infile_execute(argv, envp, paths, fd);
	ft_execute_write_outfile(argv, envp, paths, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	(void)argc;
	(void)envp;

	paths = NULL;
	if (ft_open_infile(argv[1]) == ERROR)
		return (ERROR_INFILE);
	if (ft_open_outfile(argv[2]) == ERROR)
		return (ERROR_OUTFILE);
	paths = ft_get_paths(envp);
	if (paths == NULL)
		return (ERROR_PATH);
	ft_execute_parellel(argv, envp, paths);
	return (0);
}
