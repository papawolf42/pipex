/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:26:20 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/21 04:33:30 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

/*
** utils.c
*/
void	err_msg(char *msg);
void	ft_free_split(char **strs);

/*
** file.c
*/
void	ft_open_infile(char *filename);
void	ft_open_outfile(char *filename);
char	**ft_get_paths(char **envp);
char	*ft_find_path(char **paths, char *cmd);

#endif
