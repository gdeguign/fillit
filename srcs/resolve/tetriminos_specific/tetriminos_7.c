/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:23:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/01/03 14:25:13 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fillit_resolve.h"

int	remove_tetriminos_7(t_grid *grid, int x, int y)
{
	grid->grid[y][x] = '.';
	grid->grid[y + 1][x] = '.';
	grid->grid[y + 1][x + 1] = '.';
	grid->grid[y + 1][x + 2] = '.';
	return (1);
}

int	add_tetriminos_7(t_grid *grid, int i, int x, int y)
{
	char letter;

	letter = 'A' + i;
	if (grid->grid[y][x] == '.')
	{
		if (x + 2 < grid->size && y + 1 < grid->size
			&& grid->grid[y][x] == '.'
			&& grid->grid[y + 1][x] == '.'
			&& grid->grid[y + 1][x + 1] == '.'
			&& grid->grid[y + 1][x + 2] == '.')
		{
			grid->grid[y][x] = letter;
			grid->grid[y + 1][x] = letter;
			grid->grid[y + 1][x + 1] = letter;
			grid->grid[y + 1][x + 2] = letter;
			return (1);
		}
	}
	return (0);
}
