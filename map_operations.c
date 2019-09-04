/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:40:44 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/04 15:33:15 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* TODO: Сделать саму вставку, передвигаясь по мапе по x и y */
/* TODO: Возможно имеет смысл сделать откат к предыдущей версии мапы,
или проверку возможности вставки */
/* TODO: Validate tetromino by predefined examples */

char	**ft_inserttetrotomap(char **map, size_t map_size, t_tetr *tet,
size_t x_m, size_t y_m)
{
	size_t	i;

	if (!map || map_size < 2)
		return (NULL);
	if (!tet)
		return (map);
	i = 0;
	while (tet->chunk[i])
	{
		if ((size_t)tet->chunk[i] - (size_t)'0' < map_size &&
		(size_t)tet->chunk[i + 1] - (size_t)'0' < map_size)
			if (map[tet->chunk[i] - '0'][tet->chunk[i + 1] - '0'] == '.')
				map[tet->chunk[i] - '0'][tet->chunk[i + 1] - '0'] = tet->letter;
		i += 2;
	}
	if (!tet->chunk[i])
		if ((x_m == map_size && y_m == map_size) || !tet->chunk[i])
			return (ft_inserttetrotomap(map, map_size, tet->next, 0, 0));
		else if (x_m == map_size)
			return (ft_inserttetrotomap(map, map_size, tet, 0, ++y_m));
		else
			return (ft_inserttetrotomap(map, map_size, tet, ++x_m, y_m));
	else
		return (NULL);
}

void	ft_bruteforce(t_tetr *head)
{
	size_t		map_size;
	char		**map;

	map_size = ft_findmapsize(ft_lstlen(head));
	map = NULL;
	while (!ft_inserttetrotomap(map, ++map_size, head, 0, 0))
		map = ft_initmap(map, map_size);
	ft_printmap(map);
	ft_clearmap(map);
}

// ALL THAT'S UP IS IN TEST
