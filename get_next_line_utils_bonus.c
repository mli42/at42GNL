/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:40:52 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 15:48:21 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list		*ft_lstnew_b(char *str)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->tab = str;
	new->min = 0;
	new->max = BUFFER_SIZE;
	new->next = NULL;
	return (new);
}

t_struct	*ft_addfront_fd_b(t_struct **astruct, int fd)
{
	t_struct	*new;

	if (!(new = (t_struct *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	if (!(new->list = ft_lstnew_b(NULL)))
	{
		free(new);
		return (NULL);
	}
	new->next = *astruct;
	*astruct = new;
	return (new);
}

void		ft_total_remove_fd_b(t_struct **begin_fd, t_struct *to_delete_fd)
{
	t_list		*current;
	t_list		*then;
	t_struct	*tmp_fd;

	current = to_delete_fd->list;
	while (current)
	{
		then = current->next;
		if (current->tab)
			free(current->tab);
		free(current);
		current = then;
	}
	to_delete_fd->list = NULL;
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

int			get_next_line(int fd, char **line)
{
	int					return_value;
	static t_struct		*begin_fd = NULL;
	t_struct			*right_fd;

	right_fd = begin_fd;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (right_fd && right_fd->fd != fd)
		right_fd = right_fd->next;
	if (right_fd == NULL)
	{
		if (!ft_addfront_fd_b(&begin_fd, fd))
			return (-1);
		right_fd = begin_fd;
	}
	return_value = ft_get_line_b(fd, line, &(right_fd->list));
	if (return_value == 0 || return_value == (-1))
		ft_total_remove_fd_b(&begin_fd, right_fd);
	return (return_value);
}
