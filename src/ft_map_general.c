/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:10:53 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/28 22:14:42 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_mapstrnew(size_t size)
{
	char	*mem;
	size_t	size_l;
	size_t	i;

	size_l = (size_t)size;
	if (!(mem = (char*)malloc((size_l + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size)
		mem[i++] = '.';
	mem[size] = '\0';
	return (mem);
}

t_map	*ft_initmap(t_map *map, size_t size)
{
	size_t	i;

	if (map)
		ft_clearmap(map);
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->chunk = (char**)malloc(((unsigned long)size + 1)
	* sizeof(char*))))
		return (NULL);
	i = 0;
	map->chunk[size] = NULL;
	if (map->chunk)
		while (i < size)
			map->chunk[i++] = ft_mapstrnew(size);
	return (map);
}

void	ft_printmap(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->chunk[i])
	{
		ft_putstr(map->chunk[i++]);
		ft_putchar('\n');
	}
}

void	ft_clearmap(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->chunk[i])
		ft_strdel(&map->chunk[i++]);
	ft_strdel(&map->chunk[i]);
	free(map->chunk);
	map->chunk = NULL;
	free((void*)map);
	map = NULL;
}

size_t	ft_findmapsize(size_t tetroscount)
{
	size_t	i;

	i = 2;
	while (i * i < tetroscount * 4)
		i += 1;
	return (i);
}
