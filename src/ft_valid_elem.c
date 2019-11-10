/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:13:00 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/21 17:55:16 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_valid_point(const char *grid, int i)
{
	int y;
	int x;
	int c;

	x = i % 4;
	y = i / 4;
	c = 0;
	if (y > 0 && grid[x + (y - 1) * 4] == '#')
		c++;
	if (y < 3 && grid[x + (y + 1) * 4] == '#')
		c++;
	if (x > 0 && grid[x - 1 + y * 4] == '#')
		c++;
	if (x < 3 && grid[x + 1 + y * 4] == '#')
		c++;
	return (c);
}

int			ft_valid_elem(const char *grid)
{
	int i;
	int count;
	int valid;

	i = 0;
	count = 0;
	valid = 0;
	while (grid[i] && count < 5)
	{
		if (grid[i] == '#')
		{
			valid += ft_valid_point(grid, i);
			count++;
		}
		i++;
	}
	if (count != 4 || (valid != 6 && valid != 8))
		return (1);
	return (0);
}
