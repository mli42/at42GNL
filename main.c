/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:55:01 by mli               #+#    #+#             */
/*   Updated: 2019/11/03 11:14:01 by mli              ###   ########.fr       */
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
		if ((fd = open(argv[1], O_RDONLY)))
		{
			while (gnl_r = get_next_line(fd, &line) == 1)
			{
				printf("RETURNED[1]:%s\n", line);
				free(line);
			}
			if (gnl_r == 0)
			{
				printf("RETURNED[0]:%s\n", line);
				free(line);
			}
			else if (gnl_r == -1)
			{
				printf("RETURNED[-1]:\tHAD AN ERROR || STOP\n");
				free(line);
			}
			close(fd);
		}
	return (0);
}
