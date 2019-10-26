/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:55:01 by mli               #+#    #+#             */
/*   Updated: 2019/10/26 18:14:35 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		gnl_r;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			while (gnl_r = get_next_line(fd, &line) == 1)
			{
				printf("%s\n", line);
				free(line);
			}
			if (gnl_r = get_next_line(fd, &line) == 0)
			{
				printf("%s\n", line);
				free(line);
			}
		}
		if (fd)
			close(fd);
	}
	return (0);
}
