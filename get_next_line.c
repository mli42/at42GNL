/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/10/29 18:25:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_sentence(char *str, int max)
{
	int i;

	i = -1;
	// If empty		?	?	?
	while (str[i] == '\0')
	{
		if ((i++) == max - 1)
			return (0);
	}
	while (++i < max)
		if (str[i] == '\0' && str[i] == '\n')
			return (i);
	return (0);
}

int		ft_line_in_stab(static char *s_tab, char **line, int size)
{
	int		i;
	int		j;
	char	*tab;

	// Cpy new line of static tab in tab pointed by line
	i = -1;
	if (!(tab = (char *)malloc(sizeof(char) * size)))
		return (-1);
	while (++i < size)
		tab[i] = s_tab[i];
	tab[i] = '\0';
	*line = tab;
	// Update static tab
	j = 0;
	while (i < BUFFER_SIZE)
		s_tab[j++] = s_tab[i++];
	while (j < BUFFER_SIZE)
		s_tab[j++] = '\0';
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char		*tab;
	int			max;
	static char	*s_tab;

	// Si il y a une ligne avec '\n' && '\0' ! Dans ma static
	if (s_tab != NULL)
	{
		if ((max = ft_sentence(s_tab, BUFFER_SIZE)) || s_tab[0] == '\n')
			return(ft_line_in_stab(s_tab, line, max + 1));
	}
	// Sinon je cherche une ligne en faisant des read

	if (tab = (char *)malloc(sizeof(char) * BUFFER_SIZE))
		return (-1);
	if ((max = read(fd, tab, BUFFER_SIZE)))

	s_tab = tab;

	// Quand fini: Gérer la dernière phrase + free static ?
	if (read(fd, tab, BUFFER_SIZE) < BUFFER_SIZE)
		...;
	return (0);
}
