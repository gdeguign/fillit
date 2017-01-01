/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:55:20 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 10:55:36 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_to_liste(t_liste *une_liste, int type)
{
	int		i;

	i = 0;
	while (une_liste->elem[i])
		i++;
	une_liste->elem[i] = type;
	une_liste->size++;
}

void	fill_next(foo *une_union, char move, int level)
{
	int		i;

	i = 0;
	while (une_union->myByte[i])
		i++;
	if (i < 4)
		une_union->myByte[i] = move + level;
	(void)i;
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
