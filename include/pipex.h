/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:26:20 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/21 01:05:09 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
** fcntl.h => open()
*/
# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define ERROR -1
# define ERROR_INFILE -2
# define ERROR_OUTFILE -3
# define ERROR_PATH -4

int	err_msg(char *s);

#endif
