/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:10:53 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/04 15:55:05 by rdremora         ###   ########.fr       */
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

/*void	ft_printmap(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

void	ft_clearmap(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		ft_strdel(&map[i++]);
	ft_strdel(&map[i]);
	free(map);
	map = NULL;
}

char	**ft_initmap(char **map, size_t size)
{
	size_t			i;

	if (map)
		ft_clearmap(map);
	if (size < 2)
		return (NULL);
	printf("Now the size of map is: %zu\n", size);
	if (!(map = (char**)malloc(((unsigned long)size + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	map[size] = NULL;
	while (i < size)
		map[i++] = ft_mapstrnew((size_t)size);
	return (map);
}*/

// ALL THAT'S UP IS PERFECTLY WORKING

t_map	*ft_initmap(t_map *map, size_t size)
{
	size_t			i;

	if (map)
		ft_clearmap(map);
	if (size < 2)
		return (NULL);
	else
	{
		map = (t_map*)malloc((sizeof(t_map)));
		map->size = size;
	}
	printf("Now the size of map is: %zu\n", map->size);
	if (!(map->chunk = (char**)malloc(((unsigned long)map->size + 1)
	* sizeof(char*))))
		return (NULL);
	i = 0;
	map->chunk[map->size] = NULL;
	while (i < map->size)
		map->chunk[i++] = ft_mapstrnew((size_t)map->size);
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
	free(map);
	map = NULL;
}
