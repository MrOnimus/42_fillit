/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:06:15 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	t;
	unsigned char	*td;
	unsigned char	*ts;

	t = (unsigned char)c;
	td = (unsigned char*)dst;
	ts = (unsigned char*)src;
	while (n--)
	{
		*td = *ts;
		if (*ts == t)
			return ((void*)(td + 1));
		td++;
		ts++;
	}
	return (NULL);
}
