/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_filein.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naoki <naoki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:54:19 by naoki             #+#    #+#             */
/*   Updated: 2022/12/23 19:13:37 by naoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line1;
	char	*line2;
	char	*line3;
	int		fd1;
	int		fd2;
	int		fd3;
	int		i;

	fd1 = open("tests/test1.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 0;
	printf("__test1__\n");
	while (i < 11)
	{
		line1 = get_next_line(fd1);
		printf("[%d]%s", i + 1, line1);
		i++;
	}
	printf("\n");
	i = 0;
	printf("__test2__\n");
	while (i < 1)
	{
		line2 = get_next_line(fd2);
		printf("[%d]%s", i + 1, line2);
		i++;
	}
	printf("\n");
	i = 0;
	printf("__test3__\n");
	while (i < 8)
	{
		line3 = get_next_line(fd3);
		printf("[%d]%s", i + 1, line3);
		i++;
	}
	printf("\n");
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
