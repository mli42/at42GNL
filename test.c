/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:53:29 by mli               #+#    #+#             */
/*   Updated: 2019/11/03 16:02:46 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		have_read;
	char	line[5];
	int		fd;
	int		i;

	i = 5;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			have_read = read(fd, line, i);
			printf("Read %d chars\n", have_read);
			write(1, line, i);
//			write(1, "\n", 1);

	//		write(1, "||\n\n", 4);
//			read(fd, line, 5);
//			write(1, line, 5);
//			write(1, "\n", 1);

//			write(1, "||\n\n", 4);
//			read(fd, line, 5);
//			write(1, line, 5);
//			write(1, "\n", 1);
(void)have_read;
//			have_read = read(fd, line, 5);
//			write(1, line, have_read);
//			write(1, "\n", 1);
			close(fd);
		}
	}
	return (0);
}
