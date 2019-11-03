/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/03 16:39:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_has_sentence(char *str, int min, int max)
{
	int i;

	i = min;
	while (min < max)
		if (str[min++] == '\n')
			return (min - i);
	return (0);
}

int		ft_found(char *src, char **line, int size, int *min)
{
	int i;

	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (-1);
	i = 0;
	while (i < size - 1)
		line[0][i++] = src[(*min)++];
	line[0][i] = '\0';
	return (1);
}

int		ft_get_line(int fd, char **line, t_list **alst)
{
	int			size;
	//char		*tab;
	t_list		*lst;

	lst = *alst;
	if (lst->tab == NULL)
	{
		if (!(lst->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
		lst->max = read(fd, lst->tab, BUFFER_SIZE);
	}
	if (lst->tab != NULL)
		if ((size = ft_has_sentence(lst->tab, lst->min, lst->max)))
			return (ft_found(lst->tab, line, size, &(lst->min)));


//	while (list && list->content && !ft_has_sentence(list->content))
//		list = list->next;



	return (0);
}
