/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdremora <rdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:41:18 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/28 22:15:20 by rdremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# define EL_MAX 26

typedef struct		s_elems
{
	char			*coords;
	char			letter;
	size_t			height;
	size_t			width;
	struct s_elems	*next;
}					t_elems;

typedef struct		s_map
{
	char			**chunk;
	size_t			size;
}					t_map;

int					ft_read_elems(t_elems **elems, int fd);
int					ft_valid_elem(char *grid);
void				ft_free_elems(t_elems **elems);
void				ft_rev_elems(t_elems **elems);

char				*ft_get_coords(const char *grid);
size_t				ft_getdimension(char *coords, size_t i);
size_t				ft_getmax(size_t a, size_t b);
void				ft_adddimensions(t_elems *tet);

t_map				*ft_initmap(t_map *map, size_t size);
void				ft_printmap(t_map *map);
void				ft_clearmap(t_map *map);
size_t				ft_findmapsize(size_t tetroscount);

int					ft_inserttetros(t_map *map, t_elems *tet);
char				*ft_mapstrnew(size_t size);
void				ft_bruteforce(t_elems *head, int len);
size_t				ft_gettetrmaxdmnsn(char *chunk, size_t i);
void				ft_placetetr(t_map *map, t_elems *tet,
size_t x_m, size_t y_m);
size_t				ft_checkplacement(t_map *map, t_elems *tet,
size_t x_m, size_t y_m);
void				ft_deltetr(t_map *map, t_elems *tet);

#endif
