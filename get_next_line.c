/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/02 18:48:57 by mli              ###   ########.fr       */
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

void	ft_found(char *src, char **line, int size)
{
	int begin;

	begin = 0;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (-1);
	while (--size >= 0)
		line[size] = src[begin++];
	return (1);
}

int		ft_get_line(int fd, char **line, t_list **alst)
{
	int			max;
	int			size;
	char		*tab;
	t_list		*list;

	list = *alst;
	tab = list->content;
	if (tab != NULL)
		if ((size = ft_has_sentence(tab, BUFFER_SIZE)));

	while (list && !ft_has_sentence(list->content))
		list = list->next;



	return (0);
}
