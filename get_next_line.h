/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:43:26 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 12:23:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				min;
	int				max;
	char			*tab;
	struct s_list	*next;
}				t_list;

typedef struct	s_struct
{
	int				fd;
	t_list			*list;
	struct s_struct	*next;
}				t_struct;

int				get_next_line(int fd, char **line);
int				ft_get_line(int fd, char **line, t_list **alst);
t_struct		*ft_addfront_fd(t_struct **astruct, int fd);
t_list			*ft_lstnew(char *str);

#endif
