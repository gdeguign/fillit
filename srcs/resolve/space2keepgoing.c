#include "fillit.h"
#include "fillit_resolve.h"

extern int (*g_add_tetriminos[])(t_grid *grid, int i, int x, int y);
extern int (*g_remove_tetriminos[])(t_grid *grid, int x, int y);

void count(t_grid *grid, int x, int y, int *ret)
{
	if ((unsigned)x < (unsigned)grid->size 
		&& (unsigned)y < (unsigned)grid->size
		&& grid->grid[y][x] == '.')
	{
		grid->grid[y][x] = '0';
		(*ret)++;
		count(grid, x + 1, y, ret);
		count(grid, x, y + 1, ret);
		count(grid, x - 1, y, ret);
		count(grid, x, y - 1, ret);
	}
}

int check_possibility(t_grid *grid, t_liste *list, t_coord *c, int blocked)
{
	int i;

	i = 0;
	if (blocked == 4)
	{
		while (i < list->size)
		{
			if (g_add_tetriminos[list->elem[i]](grid, i, *c->x, *c->y))
			{
				g_remove_tetriminos[list->elem[i]](grid, *c->x, *c->y);
				return (1);
			}
			++i;
		}
	}
	return (0);
}

int how_many_blocked(t_grid *grid, t_liste *list)
{
	int x;
	int y;
	int blocked;
	int tmp_blocked;

	y = -1;
	blocked = 0;
	(void)list;
	while (++y < grid->size)
	{
		x = -1;
		while (++x < grid->size)
		{
			if (grid->grid[y][x] == '.')
			{
				tmp_blocked = 0;
				count(grid, x, y, &tmp_blocked);
				// if (check_possibility(grid, list, &(t_coord){&x, &y}, tmp_blocked))
				// 	return (grid->size * grid->size);
				blocked += tmp_blocked < 4 ? tmp_blocked : 0;
			}
		}
	}
	return (blocked);
}

void clean_grid(t_grid *grid)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < grid->size)
	{
		x = 0;
		while (x < grid->size)
		{
			if (grid->grid[y][x] == '0')
				grid->grid[y][x] = '.';
			++x;
		}
		++y;
	}
}

int space2keepgoing(t_grid *grid, t_liste *list)
{
	int blocked;

	blocked = how_many_blocked(grid, list);
	clean_grid(grid);
	if ((grid->size * grid->size) - (list->size * 4) < blocked)
		return (0);
	return (1);
}