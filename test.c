/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:53:29 by mli               #+#    #+#             */
/*   Updated: 2019/10/29 16:02:02 by mli              ###   ########.fr       */
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

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			read(fd, line, 5);
			write(1, line, 5);
			write(1, "\n", 1);

			read(fd, line, 5);
			write(1, line, 5);
			write(1, "\n", 1);

			have_read = read(fd, line, 5);
			write(1, line, have_read);
			write(1, "\n", 1);
		}
		if (fd)
			close(fd);
	}
	return (0);
}
