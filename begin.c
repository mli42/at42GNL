/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:23:00 by mli               #+#    #+#             */
/*   Updated: 2019/11/02 16:22:00 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <stdio.h>
//#include <fcntl.h>

void	ft_total_remove_fd(t_struct **right_fd)
{
	t_list		*current;
	t_list		*then;
	t_struct	*to_delete;

	current = (*right_fd)->list;
	while (current)
	{
		then = current->next;
		free(current);
		current = then;
	}
	(*right_fd)->list = NULL;
	// Last to do
	to_delete = *right_fd;
	*right_fd = to_delete->next;
	free(to_delete);
}

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
		if (!ft_addfront_fd(&begin_fd, fd))
			return (-1);
		right_fd = begin_fd;
	}
	return_value = ft_get_line(fd, line, &(right_fd->list));
	if (return_value == 0 || return_value == (-1))
		ft_total_remove_fd(&right_fd);
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
