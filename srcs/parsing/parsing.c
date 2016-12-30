/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:55:20 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 10:55:36 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//open
#include <fcntl.h>
//read
#include <sys/types.h>

void		init_tetriminos_tab(t_liste *la_liste)
{
	la_liste->tab_type[0] = CARRE;
	la_liste->tab_type[1] = BARRE_V;
	la_liste->tab_type[2] = BARRE_H;
	la_liste->tab_type[3] = Z1;
	la_liste->tab_type[4] = Z2;
	la_liste->tab_type[5] = Z3;
	la_liste->tab_type[6] = Z4;
	la_liste->tab_type[7] = L_H1;
	la_liste->tab_type[8] = L_H2;
	la_liste->tab_type[9] = L_H3;
	la_liste->tab_type[10] = L_H4;
	la_liste->tab_type[11] = L_V1;
	la_liste->tab_type[12] = L_V2;
	la_liste->tab_type[13] = L_V3;
	la_liste->tab_type[14] = L_V4;
	la_liste->tab_type[15] = T1;
	la_liste->tab_type[16] = T2;
	la_liste->tab_type[17] = T3;
	la_liste->tab_type[18] = T4;
}

void	ft_check_shape(t_liste *une_liste, char *tab)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	while (i < 4)
	{
		while(j < 4)
		{
			if (tab[(i * 5) + j] == '#')
				nb++;
			if (!(tab[(i * 5) + j] == '.' || tab[(i * 5) + j] == '#'))
			{	
				ft_print("erreur 1 au caractere [%c]      i=[%d], j=[%d]", tab[(i * 5) + j], i, j);
				une_liste->error = 1;
			}
			j++;
		}
		if (!(tab[(i * 5) + 4] == '\n' || tab[(i * 5) + 4] == '\0'))
		{	
			ft_print("erreur 2 au caractere [%c]    i=[%d]", tab[(i * 5) + 4], i);
			une_liste->error = 1;
		}
		j = 0;
		i++;
	}
	if (nb != 4)
		une_liste->error = 1;
}

int		*realloc_tetriminos_tab(t_liste *une_liste)
{
	int		*new_tab;

	if ((new_tab = (int*)malloc(sizeof(int) * une_liste->capacite * 2)) == NULL)
		return (NULL);

	une_liste->capacite = une_liste->capacite * 2;
	ft_bzero(une_liste->elem, sizeof(int) * une_liste->capacite);
	ft_memcpy(new_tab, une_liste->elem, sizeof(int) * une_liste->capacite);
	free(une_liste->elem);
	une_liste->elem = NULL;
	return (new_tab);
}

/*
i = 9
x = 4
y = 1
9 % 5
4
9 / 5
1
*/

void	fill_next(foo *une_union, char move, int level)
{
	int		i;

	i = 0;
	while (une_union->myByte[i])
		i++;
	if (i < 4)
		une_union->myByte[i] = move + level;
}

void	get_move(char *tab, foo *une_union, int i, int level)
{
	int		x;
	int		y;
	int		tmp;
	
	tmp = i;
	if (tab[i] == '#')
	{
		x = i % 5;
		y = i / 5;
		// ft_print("la valeur de x est [%d] la valeur de y est [%d]    la valeur de i est [%d]\n", x, y, i);
		tab[i] = '.';
		if (x > 0)
		{
			if (tab[i - 1] == '#')
			{
				// ft_print("je suis laaaa get move  GGGGGGGGGGGGGGg\n");
				fill_next(une_union, 'g', level);
	 			get_move(tab, une_union, i - 1, level + 1);
	 		}
		}
		if (x < 5)
		{
			if (tab[i + 1] == '#')
			{
				// ft_print("je suis laaaa get move  DDDDDDDDDDDDDDDD\n");
				fill_next(une_union, 'd', level);
				get_move(tab, une_union, i + 1, level + 1);
			}
		}
		if (y < 5)
		{
			if (tab[i + 5] == '#')
			{
				// ft_print("je suis laaaa get move  BBBBBBBBBBBBBBBBBB\n");
				fill_next(une_union, 'b', level);
				get_move(tab, une_union, i + 5, level + 1);
			}
		}
	}
	// ft_print(" le premier char est [%c]\n", une_union->myByte[0]);
	// ft_print(" le premier char est [%c]\n", une_union->myByte[1]);
	// ft_print(" le premier char est [%c]\n", une_union->myByte[2]);
}

#include <stdio.h>

int		get_tetriminos_type(t_liste *une_liste, char *tab)
{
	int		i;
	int		type_val;
	foo		une_union;

	i = 0;
	type_val = -1;
	une_union.mylong = 0;
	if (une_liste->capacite == une_liste->size)
		une_liste->elem = realloc_tetriminos_tab(une_liste);
	while (tab[i] != '#')
		i++;
	get_move(tab, &une_union, i, 0);
	if (une_union.myByte[0] != '\0' && une_union.myByte[1] != '\0' && une_union.myByte[2] != '\0')
		 ;
	else
		une_liste->error = 1;
	printf("++++++++++++++++++la valeur du long est de [%ld]++++++++++\n", une_union.mylong);
	i = 0;
	while (une_liste->tab_type[i])
	{
		// ft_print("[%s]-------\n", une_liste->tab_type[i]);
		if (une_union.mylong == une_liste->tab_type[i])
		{
			type_val = i;
			break ;
		}
		i++;
	}
	ft_print("val de i [%d]\n", i);
	//ft_print("affichage de val de ret de get_tetriminos_type [%d]\n", type_val);
	ft_print("affichage de tab_type [%ld]\n", une_union.mylong);
	//ft_print("affichage de tab [%s]\n", tab);
	
	if (i > 18 || type_val == -1)
		une_liste->error = 1;
	return (type_val);
}

void	add_to_liste(t_liste *une_liste, int type)
{
	int		i;

	i = 0;
	while (une_liste->elem[i])
		i++;
	une_liste->elem[i] = type;
	une_liste->size++;
}

void	ft_add_tetriminos(t_liste *une_liste, char *tab)
{
	int		i;
	int		type;

	i = 0;
	ft_check_shape(une_liste, tab);
	if (une_liste->error == 1)
		return ;
	type = get_tetriminos_type(une_liste, tab);
	if (une_liste->error == 1)
		return ;
	add_to_liste(une_liste, type);
	// ft_print("le terminos trouvee est[%d]\n", type);
	// while (x)
	// while (une_liste->elem[i])
	// 	i++

	// ft_print("pas dereurs trouvee !@@!!!!\n");
}

void	free_t_liste(t_liste *une_liste)
{
	if (une_liste == NULL)
		return ;
	if (une_liste->elem)
	{
		free(une_liste->elem);
		une_liste->elem = NULL;
	}
	if (une_liste)
	{	
		free(une_liste);
		une_liste = NULL;
	}
}

t_liste		*parser(char *file_name, t_liste *la_liste)
{
	int		fd;
	int		ret;
	char	tab[21];

	if ((la_liste = (t_liste*)malloc(sizeof(t_liste))) == NULL)
		return (NULL);
	la_liste->size = 0;
	la_liste->error = 0;
	la_liste->capacite = 40;
	if ((la_liste->elem = (int*)malloc(sizeof(int) * 40)) == NULL)
	{
		free(la_liste);
		return (NULL);
	}
	init_tetriminos_tab(la_liste);
	ft_bzero(la_liste->elem, sizeof(int) * 40);
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		free_t_liste(la_liste);
		return (NULL);
	}
	ft_bzero(tab, 21 * sizeof(char));
	while ((ret = read(fd, tab, sizeof(char) * 21)) > 0)
	{
		if (la_liste->error == 1)
			break ;
		write(1, tab, 21);
		ft_add_tetriminos(la_liste, tab);
		if (la_liste->error)
			break;
		if (!(tab[20] == '\0' || tab[20] == '\n'))
		{
			la_liste->error = 1;
			break ;
		}
		ft_bzero(tab, 21 * sizeof(char));
	}
	close(fd);
	return (la_liste);
}

void	print_liste_elem(t_liste *une_liste)
{
	int 	i;

	i = 0;
	while (i < une_liste->size)
	{
		ft_print("%d\n", une_liste->elem[i]);
		i++;
	}
}
