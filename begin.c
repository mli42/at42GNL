/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:23:00 by mli               #+#    #+#             */
/*   Updated: 2019/11/06 17:02:11 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include <stdio.h>
//#include <fcntl.h>

void	ft_total_remove_fd(t_struct **begin_fd, t_struct *to_delete_fd)
{
	t_list		*current;
	t_list		*then;
	t_struct	*tmp_fd;

	current = to_delete_fd->list;
	while (current)
	{
		then = current->next;
		free(current);
		current = then;
	}
	to_delete_fd->list = NULL;
	// Last to do
	if (*begin_fd == to_delete_fd)
		*begin_fd = to_delete_fd->next;
	else
	{
		tmp_fd = *begin_fd;
		while (tmp_fd->next && tmp_fd->next != to_delete_fd)
			tmp_fd = tmp_fd->next;
		tmp_fd->next = tmp_fd->next->next;
	}
	free(to_delete_fd);
}

int		get_next_line(int fd, char **line)
{
	int					return_value;
	static t_struct		*begin_fd;
	t_struct			*right_fd;

	right_fd = begin_fd;
	// Have to protect
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
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
		ft_total_remove_fd(&begin_fd, right_fd);
	return (return_value);
}
