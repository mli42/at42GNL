/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:37:05 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 15:40:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_has_sentence_b(t_list **begin_list, int min, int max)
{
	int		size;
	char	*str;
	t_list	*lst;

	size = 0;
	lst = *begin_list;
	while (lst->next)
	{
		size += lst->max - lst->min;
		lst = lst->next;
	}
	str = lst->tab;
	while (min < max)
	{
		size++;
		if (str[min++] == '\n')
			return (size);
	}
	return (0);
}

void	ft_lstremove_b(t_list **alst)
{
	t_list	*tmp;

	while ((*alst)->next)
	{
		tmp = (*alst);
		*alst = (*alst)->next;
		free(tmp->tab);
		free(tmp);
	}
}

int		ft_found_b(char **line, t_list **alst, int size)
{
	int		i;
	char	*src;
	t_list	*lst;

	i = 0;
	lst = *alst;
	src = lst->tab;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (-1);
	while (i < size - 1)
	{
		if ((lst->min >= lst->max) && lst->next)
		{
			lst = lst->next;
			src = lst->tab;
		}
		line[0][i++] = src[(lst->min)++];
	}
	if ((lst->min >= lst->max) && lst->next)
		lst = lst->next;
	line[0][i] = '\0';
	(lst->min)++;
	ft_lstremove_b(alst);
	return (1);
}

int		ft_lstsize_b(t_list *lst)
{
	int i;

	i = 1;
	while (lst)
	{
		i += lst->max - lst->min;
		lst = lst->next;
	}
	return (i);
}

int		ft_get_line_b(int fd, char **line, t_list **alst)
{
	int			size;
	t_list		*lst;

	lst = *alst;
	if (lst->tab == NULL)
	{
		if (!(lst->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
		if ((lst->max = read(fd, lst->tab, BUFFER_SIZE)) == -1)
			return (-1);
	}
	while (((size = ft_has_sentence_b(alst, lst->min, lst->max)) == 0) &&
			(lst->max == BUFFER_SIZE || (fd == 0 && lst->max > 0)))
	{
		if ((!(lst->next = ft_lstnew_b(NULL))) ||
			(!(lst->next->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE))))
			return (-1);
		lst = lst->next;
		if ((lst->max = read(fd, lst->tab, BUFFER_SIZE)) == -1)
			return (-1);
	}
	if (ft_found_b(line, alst, (size ? size : ft_lstsize_b(*alst))) == -1)
		return (-1);
	return ((size ? 1 : 0));
}
