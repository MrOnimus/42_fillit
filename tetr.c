/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:10:31 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/01 16:38:01 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_optimtetr(char **m_chunk)
{
	while ((*m_chunk)[0] > '0' && (*m_chunk)[2] > '0' &&
	(*m_chunk)[4] > '0' && (*m_chunk)[6] > '0')
	{
		(*m_chunk)[0]--;
		(*m_chunk)[2]--;
		(*m_chunk)[4]--;
		(*m_chunk)[6]--;
	}
	while ((*m_chunk)[1] > '0' && (*m_chunk)[3] > '0' &&
	(*m_chunk)[5] > '0' && (*m_chunk)[7] > '0')
	{
		(*m_chunk)[1]--;
		(*m_chunk)[3]--;
		(*m_chunk)[5]--;
		(*m_chunk)[7]--;
	}
}

void	ft_minimizetetr(char **chunk)
{
	char	*m_chunk;
	size_t	i;
	size_t	j;

	if (!(m_chunk = (char*)malloc(9)))
		return ;
	m_chunk[8] = '\0';
	i = 0;
	j = 0;
	while ((*chunk)[i])
	{
		ft_putchar((*chunk)[i]);
		if ((*chunk)[i] == '#')
		{
			m_chunk[j++] = (char)(i / 5) + '0';
			m_chunk[j++] = (char)(i % 5) + '0';
		}
		i += 1;
	}
	ft_optimtetr(&m_chunk);
	free(*chunk);
	*chunk = m_chunk;
}

size_t	ft_lstlen(t_tetr *head)
{
	size_t	len;
	t_tetr	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len * 4);
}

size_t				ft_findmapsize(size_t tetroscount)
{
	size_t	i;

	i = 2;
	while (i * i < tetroscount)
		i += 1;
	return (i);
}

// ALL THAT'S UP IS PERFECTLY WORKING
