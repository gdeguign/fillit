/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:23:55 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/01/03 14:36:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fillit_resolve.h"
#include "libft.h"

#include "fillit_tetriminos_specific.h"

int	add_tetriminos(t_grid *grid, t_liste *list, int i, t_coord *c)
{
	while (*c->y < grid->size)
	{
		while (*c->x < grid->size)
		{
			if (grid->grid[*c->y][*c->x] == '.'
				&& g_add_tetriminos[list->elem[i]](grid, i, *c->x, *c->y))
				return (1);
			++(*c->x);
		}
		*c->x = 0;
		++(*c->y);
	}
	return (0);
}

int	remove_tetriminos(t_grid *grid, t_liste *list, int i, t_coord *c)
{
	g_remove_tetriminos[list->elem[i]](grid, *c->x, *c->y);
	return (0);
}

int	try(t_grid *grid, t_liste *list, int i)
{
	int x;
	int y;
	int save;

	x = 0;
	y = 0;
	save = 0;
	while (y < grid->size)
	{
		if (add_tetriminos(grid, list, i, &(t_coord){&x, &y}))
		{
			save = list->elem[i];
			list->elem[i] = 99;
			if (space2keepgoing(grid, list) && is_solution(grid, list))
				return (1);
			else
			{
				list->elem[i] = save;
				remove_tetriminos(grid, list, i, &(t_coord){&x, &y});
			}
		}
		y += x < grid->size - 1 ? 0 : 1;
		x += x < grid->size - 1 ? 1 : -x;
	}
	return (0);
}

int	is_solution(t_grid *grid, t_liste *list)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (i < list->size)
	{
		if (list->elem[i] == 99)
			size++;
		else if (try(grid, list, i))
			return (1);
		++i;
	}
	if (size == list->size)
		return (1);
	return (0);
}
