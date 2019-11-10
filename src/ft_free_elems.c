/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:43:48 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/22 16:45:45 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_elems(t_elems **elems)
{
	t_elems *head;

	if (!elems || !*elems)
		return ;
	while (*elems)
	{
		head = *elems;
		*elems = (*elems)->next;
		free(head->coords);
		free(head);
	}
}
