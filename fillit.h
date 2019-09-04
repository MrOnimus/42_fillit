/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 03:23:57 by xenomorph         #+#    #+#             */
/*   Updated: 2019/09/04 15:33:30 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_tetr
{
	char			*chunk;
	char			letter;
	struct s_tetr	*next;
}					t_tetr;

typedef struct		s_map
{
	char			**chunk;
	size_t			size;
}					t_map;

void				ft_optimtetr(char **m_chunk);
void				ft_minimizetetr(char **chunk);
void				ft_clearmap(char **map);
char				**ft_initmap(char **map, size_t size);
void				ft_printmap(char **map);

//t_map				*ft_initmap(t_map *map, size_t size);
//void				ft_printmap(char **chunk);
//void				ft_clearmap(t_map *map);

char				**ft_inserttetrotomap(char **map, size_t map_size,
t_tetr *tet, size_t x_m, size_t y_m);
char				*ft_mapstrnew(size_t size);
void				ft_bruteforce(t_tetr *head);
size_t				ft_findmapsize(size_t tetroscount);
size_t				ft_gettetrmaxdmnsn(char *chunk, size_t i);
size_t				ft_lstlen(t_tetr *head);

#endif
