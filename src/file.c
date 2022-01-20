/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:29:09 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/21 07:23:06 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_infile(char *filename)
{
	if (access(filename, F_OK) != 0)
		err_msg(filename);
	if (access(filename, R_OK) != 0)
		err_msg(filename);
}

void	ft_open_outfile(char *filename)
{
	if (access(filename, F_OK) != 0)
		return ;
	if (access(filename, W_OK) != 0)
		err_msg(filename);
}

char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH=", 5) == NULL))
		i++;
	if (envp[i] == NULL)
		err_msg("allocate");
	paths = ft_split(envp[i] + 5, ':');
	if (paths == NULL)
		err_msg("allocate");
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
			break ;
		free(path);
		i++;
	}
	if (paths[i] == NULL)
		err_msg(cmd);
	return (path);
}
