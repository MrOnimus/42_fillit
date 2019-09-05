/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:10:50 by rdremora          #+#    #+#             */
/*   Updated: 2019/09/05 18:19:11 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int		main(void)	// TO TEST ft_minimizetetr
{
	char	*tetr;

	tetr = (char*)malloc(20);
	strcpy(tetr, "...#\n...#\n...#\n...#\0");
	ft_minimizetetr(&tetr);
	ft_putstr("\nFinal result is:\n");
	ft_putstr(tetr);
	return (0);
}*/

int		main(void)	// TO TEST ft_inserttetrotomap
{
	t_tetr	*head;

	head = (t_tetr*)malloc(sizeof(t_tetr));
	head->chunk = "00011121\0";
	head->letter = 'A';
	head->next = (t_tetr*)malloc(sizeof(t_tetr));
	head->next->chunk = "00010203\0";
	head->next->letter = 'B';
	head->next->next = (t_tetr*)malloc(sizeof(t_tetr));
	head->next->next->chunk = "00101112\0";
	head->next->next->letter = 'C';
	head->next->next->next = (t_tetr*)malloc(sizeof(t_tetr));
	head->next->next->next->chunk = "00011112";
	head->next->next->next->letter = 'D';
	head->next->next->next->next = NULL;
	ft_bruteforce(head);
}

/*int		main(void)	// TO TEST ft_gettetrmaxdimension and ft_getmax
{
	char	*chunk;

	chunk = "00102030\0";
	printf("%zu\n", ft_getmax(ft_gettetrmaxdmnsn(chunk, 0),
	ft_gettetrmaxdmnsn(chunk, 1)));
	chunk = "00100111\0";
	printf("%zu\n", ft_getmax(ft_gettetrmaxdmnsn(chunk, 0),
	ft_gettetrmaxdmnsn(chunk, 1)));
	return (0);
}*/

/*int		main(void)	// TO TEST ft_initmap ft_printmap ft_clearmap
{
	char	**map = ft_initmap(NULL, 2);
	ft_printmap(map);
	ft_clearmap(map);
}*/

/* int		main(void)	// TO TEST ft_mapstrnew
{
	char *l = ft_mapstrnew(2);
	ft_putstr(l);
	ft_strdel(&l);
	return (0);
} */

/*int		main(void)	// TO TEST ft_bruteforce
{
	ft_bruteforce(NULL);
	return (0);
}*/

/*int		main(void)	// TO TEST ft_initmap self-destruct mechanisms
{
	char	**map = ft_initmap(NULL, 2);
	map = ft_initmap(map, 3);
	map = ft_initmap(map, 4);
	ft_printmap(map);
	ft_clearmap(map);
}*/

/*int		main(void)	// TO TEST ft_lstlen
{
	t_tetr	*head;

	head = (t_tetr*)malloc(sizeof(t_tetr));
	head->chunk = "00102030\0";
	head->letter = 'A';
	head->next = (t_tetr*)malloc(sizeof(t_tetr));
	head->next->chunk = "00102030\n";
	head->next->letter = 'B';
	head->next->next = NULL;
	printf("%zu\n", ft_lstlen(head));
	return (0);
}*/
