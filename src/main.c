/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunkim <gunkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:25:32 by gunkim            #+#    #+#             */
/*   Updated: 2022/01/20 23:06:21 by gunkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/*
** 일단 구현하고, 뒤에 수정하자.
** check file1 exist
** 여기서 open해서 fd를 받겠지
** envp의 PATH를 가져와 while 돌면서
** accessable path를 2개 malloc하고, access함수로 체크.
** cmdpath1, cmdpath2를 가져야함.
** check cmd1 and cmd2 executable
** 
** 이제 open함수는 근데 언제쓰지?
** 1. 위 3개 파일 체크한 직후
** 2. fork 뜨고 난 다음.
** 먼가 깔끔한건 2번 fork한다음에 stdout을 open에 연결하고 하는게 맞을 거 같음.
** 
** fork 1 execute
** fork 2 execute
** terminate
*/
int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)envp;

	if (ft_open_infile(argv[1]) == ERROR)
		return (1);
	if (ft_open_outfile(argv[2]) == ERROR)
		return (1);
	return (0);
}
