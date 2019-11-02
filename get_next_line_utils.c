/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:35 by mli               #+#    #+#             */
/*   Updated: 2019/11/02 18:51:25 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstnew(char *str)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content = str;
	new->min = 0;
	new->next = NULL;
	return (new);
}

t_struct	*ft_addfront_fd(t_struct **astruct, int fd)
{
	t_struct	*new;

	if (!(new = (t_struct *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	// Initialize first maillon
	if (!(new->list = ft_lstnew(NULL)))
	{
		free(new);
		return (NULL);
	}
	// ADD FRONT
	new->next = *astruct;
	*astruct = new;
	return (new);
}
