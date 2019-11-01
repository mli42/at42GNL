/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:43:26 by mli               #+#    #+#             */
/*   Updated: 2019/11/01 18:07:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char			**content;
	struct s_lst	*next;
}				t_list

typedef struct	s_struct
{
	int			fd;
	static char	*s_tab;
	t_list		*list;
}				t_struct

#endif
