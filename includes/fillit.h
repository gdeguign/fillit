/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:08:02 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 11:09:45 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define CARRE       6906724L
# define BARRE_V     6579042L
# define BARRE_H     6710628L
# define Z1          6710116L
# define Z2          6840932L
# define Z3          6580322L
# define Z4          6579554L
# define L_H1        6710626L
# define L_H2        6448484L
# define L_H3        6908002L
# define L_H4        6579556L
# define L_V1        6513252L
# define L_V2        6710114L
# define L_V3        6906722L
# define L_V4        6579044L
# define T1          6645858L
# define T2          6514018L
# define T3          6514020L
# define T4          6514786L

typedef struct		s_liste
{
	int				*elem;
	int				size;
	int				capacite;
	int				error;
	long			tab_type[19];
}					t_liste;

typedef union
{
	char			my_byte[4];
	long			mylong;
}					t_foo;

t_liste				*parser(char *file_name, t_liste *la_liste);
void				free_t_liste(t_liste *une_liste);
void				print_liste_elem(t_liste *une_liste);
t_liste				*ft_init(t_liste *la_liste, int *fd, char *file_name);
int					*realloc_tetriminos_tab(t_liste *une_liste);
void				fill_next(t_foo *une_union, char move, int level);
void				add_to_liste(t_liste *une_liste, int type);
void				check_if_resize(t_liste *une_liste);

int					resolve(t_liste *list);

#endif
