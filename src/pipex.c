/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:25:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/14 19:42:50 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	rtn;

	(void)envp;
	if (argc != 5)
		err_msg(NULL);
	rtn = access(argv[1], F_OK);
	printf("rtn : %d\n", rtn);
	return (0);
}
