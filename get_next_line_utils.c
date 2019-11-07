/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:45:35 by mli               #+#    #+#             */
/*   Updated: 2019/11/07 21:45:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_calloc(int size)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}

t_list		*ft_lstnew(char *str)
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
