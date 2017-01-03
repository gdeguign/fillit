/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:23:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/01/03 14:24:39 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fillit_resolve.h"

int	remove_tetriminos_1(t_grid *grid, int x, int y)
{
	grid->grid[y][x] = '.';
	grid->grid[y + 1][x] = '.';
	grid->grid[y + 2][x] = '.';
	grid->grid[y + 3][x] = '.';
	return (1);
}

int	add_tetriminos_1(t_grid *grid, int i, int x, int y)
{
	char letter;

	letter = 'A' + i;
	if (grid->grid[y][x] == '.')
	{
		if (y + 3 < grid->size
			&& grid->grid[y][x] == '.'
			&& grid->grid[y + 1][x] == '.'
			&& grid->grid[y + 2][x] == '.'
			&& grid->grid[y + 3][x] == '.')
		{
			grid->grid[y][x] = letter;
			grid->grid[y + 1][x] = letter;
			grid->grid[y + 2][x] = letter;
			grid->grid[y + 3][x] = letter;
			return (1);
		}
	}
	return (0);
}
