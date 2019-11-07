/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/07 19:11:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_has_sentence(t_list **begin_list, int min, int max)
{
	int		size;
	char	*str;
	t_list	*lst;

	size = 0;
	lst = *begin_list;
	while (lst->next)
	{
		size += BUFFER_SIZE;
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

int		ft_found(char **line, t_list **alst, int size)
{
	int		i;
	char	*src;
	t_list	*lst;
	t_list	*tmp;

	i = 0;
	lst = *alst;
	src = lst->tab;
	if (!(*line = (char *)malloc(sizeof(char) * size)))
		return (-1);
	while (i < size - 1)
	{
		if ((lst->min >= lst->max) && lst->next)
		{
			tmp = lst->next;
			free(lst->tab);
			free(lst);
			lst = tmp;
			src = lst->tab;
		}
		line[0][i++] = src[(lst->min)++];
	}
	line[0][i] = '\0';
	(lst->min)++;
	*alst = lst;
	return (1);
}

int		ft_lstsize(t_list *lst)
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

int		ft_get_line(int fd, char **line, t_list **alst)
{
	int			size;
	t_list		*lst;
	char		*tmp_tab;

	lst = *alst;
	// Init la "static"
	if (lst->tab == NULL)
	{
		if (!(lst->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
		lst->max = read(fd, lst->tab, BUFFER_SIZE);
	}
	// Cherche \n dans ma "static"
	// On va read jusqu'à trouver \n || read < BUFF_SIZE == EOF
	while (((size = ft_has_sentence(alst, lst->min, lst->max)) == 0) &&
			(lst->max == BUFFER_SIZE))
	{
		if ((!(tmp_tab = (char *)malloc(sizeof(char) * BUFFER_SIZE))) ||
			(!(lst->next = ft_lstnew(tmp_tab))))
			return (-1);
		lst = lst->next;
		lst->max = read(fd, lst->tab, BUFFER_SIZE);
	}
	// Something found ! Either a \n or EOF
	if (ft_found(line, alst, (size ? size : ft_lstsize(*alst))) == -1)
		return (-1);
	return ((size ? 1 : 0));
}
