/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:50:12 by mli               #+#    #+#             */
/*   Updated: 2019/11/11 16:10:43 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
int				ft_get_line_b(int fd, char **line, t_list **alst);
t_struct		*ft_addfront_fd_b(t_struct **astruct, int fd);
t_list			*ft_lstnew_b(char *str);

#endif
