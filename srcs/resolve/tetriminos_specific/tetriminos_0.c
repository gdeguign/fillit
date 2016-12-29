#include "fillit.h"
#include "fillit_resolve.h"

int remove_tetriminos_0(t_grid *grid, int x, int y)
{
	grid->grid[y][x] = '.';
	grid->grid[y + 1][x + 1] = '.';
	grid->grid[y + 1][x] = '.';
	grid->grid[y][x + 1] = '.';
	return (1);
}

int add_tetriminos_0(t_grid *grid, int i, int x, int y)
{
	char letter;

	letter = 'A' + i;
	if (grid->grid[y][x] == '.')
	{
		if (x + 1 < grid->size && y + 1 < grid->size)
		{
			if (grid->grid[y + 1][x] == '.'
				&& grid->grid[y][x + 1] == '.'
				&& grid->grid[y +1][x + 1] == '.')
			{
				grid->grid[y][x] = letter;
				grid->grid[y + 1][x + 1] = letter;
				grid->grid[y + 1][x] = letter;
				grid->grid[y][x + 1] = letter;
				return (1);
			}
		}
	}
	return (0);
}