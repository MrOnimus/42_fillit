/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:40:44 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/04 17:30:24 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* TODO: Сделать саму вставку, передвигаясь по мапе по x и y */
/* TODO: Возможно имеет смысл сделать откат к предыдущей версии мапы,
или проверку возможности вставки */
/* TODO: Validate tetromino by predefined examples */

/*char	**ft_inserttetros(char **map, size_t map_size, t_tetr *tet,
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
			return (ft_inserttetros(map, map_size, tet->next, 0, 0));
		else if (x_m == map_size)
			return (ft_inserttetros(map, map_size, tet, 0, ++y_m));
		else
			return (ft_inserttetros(map, map_size, tet, ++x_m, y_m));
	else
		return (NULL);
}*/

size_t	ft_checkplacement(t_map *map, t_tetr *tet, size_t x_m, size_t y_m)
{
	size_t	i;

	i = 0;
	while (tet->chunk[i])
	{
		if ((size_t)tet->chunk[i] - (size_t)'0' < map->size &&
		(size_t)tet->chunk[i + 1] - (size_t)'0' < map->size)
			if (map->chunk[tet->chunk[i] - '0'][tet->chunk[i + 1] - '0'] != '.')
				return (NULL);
		i += 2;
	}
	if (tet->chunk[i])
		return (NULL);
	return (1);
}

t_map	*ft_placetetr(t_map *map, t_tetr *tet, size_t x_m, size_t y_m)
{

}

t_map	*ft_inserttetros(t_map *map, t_tetr *tet, size_t x_m, size_t y_m)
{
	size_t	i;

	if (!map || map->size < 2)
		return (NULL);
	if (!tet)
		return (map);
	if (ft_checkplacement(map, tet, x_m, y_m))
	{
		map = ft_placetetr(map, tet, x_m, y_m);
	}
	else
		return (NULL);
	/*while (tet->chunk[(i += 2)])
	{
		if ((size_t)tet->chunk[i] - (size_t)'0' < map->size &&
		(size_t)tet->chunk[i + 1] - (size_t)'0' < map->size)
			if (map->chunk[tet->chunk[i] - '0'][tet->chunk[i + 1] - '0'] == '.')
				map->chunk[tet->chunk[i] - '0'][tet->chunk[i + 1] - '0'] =
				tet->letter;
	}*/
	if ((x_m == map->size && y_m == map->size))
		return (ft_inserttetros(map, tet->next, 0, 0));
	else if (x_m == map->size)
		return (ft_inserttetros(map, tet, 0, ++y_m));
	else
		return (ft_inserttetros(map, tet, ++x_m, y_m));
}

void	ft_bruteforce(t_tetr *head)
{
	t_map		*map;

	map = ft_initmap(NULL, ft_findmapsize(ft_lstlen(head)));
	while (!ft_inserttetros(map, head, 0, 0))
		map = ft_initmap(map, ++map->size);
	ft_printmap(map);
	ft_clearmap(map);
}

// ALL THAT'S UP IS IN TEST
