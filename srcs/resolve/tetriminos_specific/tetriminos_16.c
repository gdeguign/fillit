#include "fillit.h"
#include "fillit_resolve.h"

int remove_tetriminos_16(t_grid *grid, int x, int y)
{
	grid->grid[y][x] = '.';
	grid->grid[y + 1][x + 1] = '.';
	grid->grid[y + 1][x] = '.';
	grid->grid[y + 2][x] = '.';
	return (1);
}

int add_tetriminos_16(t_grid *grid, int i, int x, int y)
{
	char letter;

	letter = 'A' + i;
	if (grid->grid[y][x] == '.')
	{
		if (x + 1 < grid->size && y + 2 < grid->size
			&& grid->grid[y][x] == '.'
			&& grid->grid[y + 1][x] == '.'
			&& grid->grid[y + 2][x] == '.'
			&& grid->grid[y + 1][x + 1] == '.')
		{
			grid->grid[y][x] = letter;
			grid->grid[y + 1][x + 1] = letter;
			grid->grid[y + 1][x] = letter;
			grid->grid[y + 2][x] = letter;
			return (1);
		}
	}
	return (0);
}
