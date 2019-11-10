/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:40:44 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/28 22:16:00 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_checkplacement(t_map *map, t_elems *tet, size_t x_m, size_t y_m)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (y_m + (size_t)tet->coords[i] < map->size &&
		x_m + (size_t)tet->coords[i + 1] < map->size)
		{
			if (map->chunk[y_m + tet->coords[i]]
			[x_m + tet->coords[i + 1]] != '.')
				return (0);
		}
		else
			return (0);
		i += 2;
	}
	ft_placetetr(map, tet, x_m, y_m);
	return (1);
}

void	ft_placetetr(t_map *map, t_elems *tet, size_t x_m, size_t y_m)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if ((size_t)tet->coords[i] < map->size &&
		(size_t)tet->coords[i + 1] < map->size)
			if (map->chunk[y_m + tet->coords[i]]
			[x_m + tet->coords[i + 1]] == '.')
				map->chunk[y_m + tet->coords[i]]
				[x_m + tet->coords[i + 1]] =
				tet->letter;
		i += 2;
	}
}

void	ft_deltetr(t_map *map, t_elems *tet)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->chunk[i][j] == tet->letter)
				map->chunk[i][j] = '.';
			j += 1;
		}
		i += 1;
	}
}

int		ft_inserttetros(t_map *map, t_elems *tet)
{
	size_t x_m;
	size_t y_m;

	if (!tet)
		return (1);
	y_m = 0;
	while (y_m < map->size - tet->height + 1)
	{
		x_m = 0;
		while (x_m < map->size - tet->width + 1)
		{
			if (ft_checkplacement(map, tet, x_m, y_m))
			{
				if (ft_inserttetros(map, tet->next))
					return (1);
				else
					ft_deltetr(map, tet);
			}
			x_m += 1;
		}
		y_m += 1;
	}
	return (0);
}

void	ft_bruteforce(t_elems *head, int len)
{
	t_map		*map;
	size_t		map_size;

	map_size = ft_findmapsize(len);
	map = ft_initmap(NULL, map_size);
	ft_adddimensions(head);
	while (!ft_inserttetros(map, head))
		map = ft_initmap(map, ++map_size);
	ft_printmap(map);
	ft_clearmap(map);
}
