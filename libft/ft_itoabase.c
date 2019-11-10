/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:59:00 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_basechar(unsigned int n)
{
	char *bchars;

	bchars = "0123456789ABCDEF";
	return (bchars[n]);
}

static size_t	ft_intlen(int n, int base)
{
	size_t len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n > base - 1 || n < 1 - base)
	{
		len++;
		n /= base;
	}
	return (++len);
}

char			*ft_itoabase(int n, unsigned int base)
{
	unsigned int	t;
	char			*str;
	size_t			size;

	if (base > 16 || base < 2 || (n < 0 && base != 10))
		return (NULL);
	size = ft_intlen(n, (int)base);
	if (n < 0)
		t = (unsigned int)(~n + 1);
	else
		t = (unsigned int)n;
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (t > base - 1)
	{
		str[--size] = ft_basechar(t % base);
		t /= base;
	}
	str[--size] = ft_basechar(t % base);
	if (size)
		str[--size] = '-';
	return (str);
}
