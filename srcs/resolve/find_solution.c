#include "fillit.h"
#include "fillit_resolve.h"
#include "libft.h"

#include "fillit_tetriminos_specific.h"

int add_tetriminos(t_grid *grid, t_liste *list, int i, t_coord *c)
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

int remove_tetriminos(t_grid *grid, t_liste *list, int i, t_coord *c)
{
	g_remove_tetriminos[list->elem[i]](grid, *c->x, *c->y);
	return 0;
}

// int is_solution(t_grid *grid, t_liste *list, int x, int y)
// {
// 	int i;
// 	int save;
// 	int size;

// 	i = 0;
// 	size = 0;
// 	while (i < list->size)
// 	{
// 		save = list->elem[i];
// 		if (save == 99)
// 			size++;
// 		else if (add_tetriminos(grid, list, i, &(t_coord){&x, &y}))
// 		{
// 			list->elem[i] = 99;
// 			show_grid(grid);
// 			sleep(1);
// 			if (is_solution(grid, list, x, y))
// 				return (1);
// 			else
// 			{
// 				list->elem[i] = save;
// 				remove_tetriminos(grid, list, i, &(t_coord){&x, &y});
// 			}
// 		}
// 		++i;
// 	}
// 	if (size == list->size)
// 		return (1);
// 	return (0);
// }

int is_solution(t_grid *grid, t_liste *list, int x, int y)
{
	int i;
	int save;
	int size;

	i = 0;
	size = 0;
	while (i < list->size)
	{
		save = list->elem[i];
		if (save == 99)
			size++;
		else
		{
			while (y < grid->size)
			{
				if (add_tetriminos(grid, list, i, &(t_coord){&x, &y}))
				{
					list->elem[i] = 99;
					// show_grid(grid);
					// ft_print("[%d][%c]\n", i, 'A' + i);
					// ft_print("-------------\n");
					// sleep(1);
					if (is_solution(grid, list, 0, 0))
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
		}
		++i;
	}
	if (size == list->size)
		return (1);
	return (0);
}