/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:55:30 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/28 21:15:58 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_rev_elems(t_elems **elems)
{
	t_elems *prev;
	t_elems *next;

	if (!elems)
		return ;
	prev = NULL;
	while (*elems)
	{
		next = (*elems)->next;
		(*elems)->next = prev;
		prev = *elems;
		*elems = next;
	}
	*elems = prev;
}
