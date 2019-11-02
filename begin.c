/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:23:00 by mli               #+#    #+#             */
/*   Updated: 2019/11/02 13:38:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <stdio.h>
//#include <fcntl.h>

int		get_next_line(int fd, char **line)
{
	int					return_value;
	static t_struct		*begin_fd;
	t_struct			*right_fd;

	right_fd = begin_fd;
	//		Looking for the right fd, or create it
	while (right_fd && right_fd->fd != fd)
		right_fd = right_fd->next;
	if (right_fd == NULL)
	{
		if (!ft_addfront_fd(&begin, fd))
			return (-1);
		right_fd = begin_fd;
	}
	return_value = ft_get_line(fd, line, &(right_fd->s_tab), &(right_fd->list));
	if (return_value == 0)
		ft_total_free();//HaveToCode
	return (return_value);
}

/*
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
			if (gnl_r == 0)
			{
				printf("%s\n", line);
				free(line);
			}
			else if (gnl_r == -1)
			{
				free(line);
				printf("Had an error\n");
			}
		}
		if (fd)
			close(fd);
	}
	return (0);
}
*/
