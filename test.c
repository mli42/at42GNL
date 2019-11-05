/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:53:29 by mli               #+#    #+#             */
/*   Updated: 2019/11/05 16:43:31 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

//				TEST 1
// ||||||||||||||||||||||||||||||||||||||||||
/*int		main(int argc, char **argv)
{
	int		have_read;
	char	line[5];
	int		fd;
	int		i;

	i = 5;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			have_read = read(fd, line, i);
			printf("Read %d chars\n", have_read);
			write(1, line, i);
//			write(1, "\n", 1);

	//		write(1, "||\n\n", 4);
//			read(fd, line, 5);
//			write(1, line, 5);
//			write(1, "\n", 1);

//			have_read = read(fd, line, 5);
//			write(1, line, have_read);
//			write(1, "\n", 1);
			close(fd);
		}
	}
	return (0);
}*/


//				TEST 2
// ||||||||||||||||||||||||||||||||||||||||||
/*typedef struct	s_lst
{
	int				x;
	struct s_list	*next;
}				t_lst;

void	ft_lst(int *x)
{
	int b = *x;
	b++;
	printf("%d\n", b);
}

void	ft_machin(void)
{
	int i = 0;
	t_lst *a;

	a = (t_lst *)malloc(sizeof(*a));
	while (i++ < 5)
		ft_lst(&(a->x));
}

int		main(void)
{
	ft_machin();
	return (0);
}*/


//				TEST 3
// ||||||||||||||||||||||||||||||||||||||||||
/*int		main(void)
{
	if (printf("") && printf("A\n"))
		printf("Y\n");
	return (0);
}*/
