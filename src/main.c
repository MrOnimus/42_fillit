/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:10:50 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/28 22:15:05 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			len;
	int			fd;
	t_elems		*head;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit target_map\n");
		return (-1);
	}
	else
	{
		head = NULL;
		fd = open(av[1], O_RDONLY);
		if (!(len = ft_read_elems(&head, fd)))
		{
			ft_putstr("error\n");
			ft_free_elems(&head);
			return (-1);
		}
		ft_bruteforce(head, len);
		ft_free_elems(&head);
		close(fd);
	}
	return (0);
}
