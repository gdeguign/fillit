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
#include <sys/types.h>

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
		while (j < 4)
		{
			if (tab[(i * 5) + j] == '#')
				nb++;
			if (!(tab[(i * 5) + j] == '.' || tab[(i * 5) + j] == '#'))
				une_liste->error = 1;
			j++;
		}
		if (!(tab[(i * 5) + 4] == '\n' || tab[(i * 5) + 4] == '\0'))
			une_liste->error = 1;
		j = 0;
		i++;
	}
	if (nb != 4)
		une_liste->error = 1;
}

void	get_move(char *tab, t_foo *une_union, int i, int level)
{
	int		x;
	int		y;

	if (tab[i] == '#')
	{
		x = i % 5;
		y = i / 5;
		tab[i] = '.';
		if (x > 0 && tab[i - 1] == '#')
		{
			fill_next(une_union, 'g', level);
			get_move(tab, une_union, i - 1, level + 1);
		}
		if (x < 5 && tab[i + 1] == '#')
		{
			fill_next(une_union, 'd', level);
			get_move(tab, une_union, i + 1, level + 1);
		}
		if (y < 5 && tab[i + 5] == '#')
		{
			fill_next(une_union, 'b', level);
			get_move(tab, une_union, i + 5, level + 1);
		}
	}
}

int		get_tetriminos_type(t_liste *une_liste, char *tab, t_foo *une_union)
{
	int		i;
	int		type_val;

	i = 0;
	type_val = -1;
	check_if_resize(une_liste);
	while (tab[i] != '#')
		i++;
	get_move(tab, une_union, i, 0);
	if (!(une_union->my_byte[0] != '\0' && une_union->my_byte[1] != '\0' &&\
		une_union->my_byte[2] != '\0'))
		une_liste->error = 1;
	i = 0;
	while (une_liste->tab_type[i])
	{
		if (une_union->mylong == une_liste->tab_type[i])
		{
			type_val = i;
			break ;
		}
		i++;
	}
	if (i > 18 || type_val == -1)
		une_liste->error = 1;
	return (type_val);
}

void	ft_add_tetriminos(t_liste *une_liste, char *tab)
{
	int			type;
	t_foo		une_union;

	une_union.mylong = 0;
	ft_check_shape(une_liste, tab);
	if (une_liste->error == 1)
		return ;
	type = get_tetriminos_type(une_liste, tab, &une_union);
	if (une_liste->error == 1)
		return ;
	add_to_liste(une_liste, type);
}

t_liste	*parser(char *file_name, t_liste *la_liste)
{
	int		fd;
	int		ret;
	char	tab[21];

	fd = -1;
	if ((la_liste = ft_init(la_liste, &fd, file_name)) == NULL)
		return (NULL);
	ft_bzero(tab, 21 * sizeof(char));
	while ((ret = read(fd, tab, sizeof(char) * 21)) > 0)
	{
		if (la_liste->error == 1)
			break ;
		ft_add_tetriminos(la_liste, tab);
		if (la_liste->error)
			break ;
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
