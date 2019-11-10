/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:01:46 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/28 20:26:07 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_min_coords(char *coords)
{
	while (coords[0] && coords[2] && coords[4] && coords[6])
	{
		coords[0]--;
		coords[2]--;
		coords[4]--;
		coords[6]--;
	}
	while (coords[1] && coords[3] && coords[5] && coords[7])
	{
		coords[1]--;
		coords[3]--;
		coords[5]--;
		coords[7]--;
	}
	return (coords);
}

char		*ft_get_coords(const char *grid)
{
	int		i;
	int		count;
	char	*coords;

	count = 0;
	i = 0;
	if (!(coords = (char*)malloc(sizeof(char) * 8)))
		return (NULL);
	while (grid[i])
	{
		if (grid[i] == '#')
		{
			coords[count++] = i / 4;
			coords[count++] = i % 4;
		}
		i++;
	}
	coords = ft_min_coords(coords);
	return (coords);
}

size_t		ft_getmax(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

size_t		ft_getdimension(char *coords, size_t i)
{
	long	max;

	max = 1;
	while (i < 8)
	{
		if (max < coords[i])
			max = coords[i];
		i += 2;
	}
	return (max);
}

void		ft_adddimensions(t_elems *head)
{
	t_elems *tmp;

	tmp = head;
	while (tmp)
	{
		tmp->height = ft_getdimension(tmp->coords, 0);
		tmp->width = ft_getdimension(tmp->coords, 1);
		tmp = tmp->next;
	}
}
