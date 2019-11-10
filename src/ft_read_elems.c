/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:33:41 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/28 20:57:40 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_add_elem(t_elems **elems, char **grid)
{
	t_elems *tmp;

	if (!*grid)
		return (1);
	if (ft_valid_elem(*grid) || !(tmp = (t_elems*)malloc(sizeof(t_elems))))
	{
		free(*grid);
		*grid = NULL;
		return (1);
	}
	if (!(tmp->coords = ft_get_coords(*grid)))
	{
		free(tmp);
		free(*grid);
		*grid = NULL;
		return (1);
	}
	if (!*elems)
		tmp->letter = 'A';
	else
		tmp->letter = (*elems)->letter + 1;
	tmp->next = *elems;
	*elems = tmp;
	free(*grid);
	return (0);
}

static char	*ft_add_line(char **grid, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (i < 4 && (line[i] == '.' || line[i] == '#'))
		i++;
	if (i == 4 && !line[i])
		tmp = ft_strjoin(*grid, line);
	free(*grid);
	return (tmp);
}

int			ft_read_elems(t_elems **elems, int fd)
{
	int		rd;
	int		count;
	char	*line;
	char	*grid;

	count = 0;
	grid = ft_strnew(0);
	while ((rd = get_next_line(fd, &line)) > 0 && grid && ++count / 5 < EL_MAX)
	{
		if (count % 5 == 0)
		{
			if (ft_strlen(line) || ft_add_elem(elems, &grid))
				break ;
			grid = ft_strnew(0);
		}
		else if (!(grid = ft_add_line(&grid, line)))
			break ;
		free(line);
	}
	if (rd >= 0)
		free(line);
	if (ft_add_elem(elems, &grid) || rd)
		return (0);
	ft_rev_elems(elems);
	return ((count + 1) / 5);
}
