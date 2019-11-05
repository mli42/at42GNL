/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/11/05 11:54:01 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_has_sentence(t_list *lst, int min, int max)
{
	int		i;
	char	*str;

	i = min;
	// New feature
	// New feature
	while (min > BUFFER_SIZE && lst->next)
	{
		lst = lst->next;
		min -= BUFFER_SIZE;
// 	?	max -= BUFFER_SIZE;
	}
	// New feature
	str = lst->tab;
	// New feature
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
	(*min)++;
	return (1);
}

int		ft_nothing_found_yet(t_list **alst)
{
	t_list		*lst;
	char		*tmp_tab;

	lst = *alst;
	if (!(tmp_tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (!(lst->next = ft_lstnew(tmp_tab)))
		return (-1);
	lst = lst->next;
	lst->max = read(fd, lst->tab, BUFFER_SIZE);
}

int		ft_get_line(int fd, char **line, t_list **alst)
{
	int			size;
	t_list		*lst;

	lst = *alst;
	// Init la "static"
	if (lst->tab == NULL)
	{
		if (!(lst->tab = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
			return (-1);
		lst->max = read(fd, lst->tab, BUFFER_SIZE);
	}
	// Cherche \n dans ma "static"
	if (lst->tab != NULL)
		if ((size = ft_has_sentence(lst, lst->min, lst->max)))
			return (ft_found(lst->tab, line, size, &(lst->min)));

	// Pas de \n trouvé =>
	// On va read jusqu'à trouver \n || read < BUFF_SIZE == EOF
	while (((size = ft_has_sentence(lst, lst->min, lst->max)) == 0) ||
			(lst->max == BUFFER_SIZE))
	{
		ft_nothing_found_yet(alst);
	}
	// Something found !

	*line = malloc(1);
	line[0][0] = '\0';
	return (0);
}

