/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:55:20 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 10:55:36 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

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

t_liste		*ft_init(t_liste *la_liste, int *fd, char *file_name)
{
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
	if ((*fd = open(file_name, O_RDONLY)) == -1)
	{
		free_t_liste(la_liste);
		return (NULL);
	}
	return (la_liste);
}

void		free_t_liste(t_liste *une_liste)
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
