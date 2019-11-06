/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:55:01 by mli               #+#    #+#             */
/*   Updated: 2019/11/06 16:14:35 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd[2];
	int		fd_open[2];
	int 	i = 0;

	fd_open[0] = 1; fd_open[1] = 1;
	if (argc == 3)
		if ((fd[0] = open(argv[1], O_RDONLY)) && (fd[1] = open(argv[2], O_RDONLY)))
		{
			while (fd_open[0] || fd_open[1])
			{
				fd_open[i % 2] = (get_next_line(fd[i % 2], &line) == 1);
				printf("RETURNED[%d]:%s\n", i % 2,  line);
				free(line);
				i++;
			}
			close(fd[0]);
			close(fd[1]);
		}
	return (0);
}
