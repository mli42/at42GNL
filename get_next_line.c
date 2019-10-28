/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:42:39 by mli               #+#    #+#             */
/*   Updated: 2019/10/28 17:32:47 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_sentence(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (0);
}

int		ft_line_in_stab(static char *static_tab, char **line, int to_cut)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * to_cut)))
		return (-1);

}

int		get_next_line(int fd, char **line)
{
	char		*tab;
	int			to_cut;
	static char	*static_tab = NULL;

	// Si il y a une ligne dans ma static
	if (static_tab != NULL)
	{
		if ((to_cut = ft_sentence(static_tab)) || static_tab[0] == '\n')
			return(ft_line_in_stab(static_tab, line, to_cut + 1));
	}
	// Sinon je cherche une ligne en faisant des read

	read(fd, tab, BUFFER_SIZE);
}
