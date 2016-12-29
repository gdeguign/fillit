#include "libft.h"
#include "fillit.h"
#include "fillit_resolve.h"

void free_grid(t_grid *grid)
{
	int i;

	i = 0;
	while (grid->grid && i < grid->capacity)
	{
		free(grid->grid[i]);
		++i;
	}
	free(grid->grid);
	grid->grid = 0;
}

int init_grid(t_grid *grid)
{
	int i;

	i = 0;
	grid->size = 2;
	grid->capacity = 40;
	grid->grid = (char **)ft_memalloc(sizeof(char *) * grid->capacity);
	if (!grid->grid)
		return (0);
	while (i < grid->capacity)
	{
		grid->grid[i] = (char *)ft_memalloc(sizeof(char) * grid->capacity);
		if (!grid->grid[i])
		{
			grid->capacity = i;
			free_grid(grid);
			return (0);
		}
		ft_memset(grid->grid[i], '.', grid->capacity);
		++i;
	}
	return (1);
}

int check_capa(t_grid *grid)
{
	int i;
	char **map;

	i = 0;
	if (grid->size > grid->capacity)
	{
		map = (char **)ft_memalloc(sizeof(char *) * (grid->capacity + 40));
		if (!map)
		{
			free_grid(grid);
			return (0);
		}
		while (i < grid->capacity)
			map[i] = grid->grid[i];
		grid->capacity += 40;
		free(grid->grid);
		grid->grid = map;
	}
	return (1);
}

void show_grid(t_grid *grid)
{
	int i;

	i = -1;
	while (grid->grid && grid->grid[++i] && i < grid->size)
	{
		write(1, grid->grid[i], grid->size);
		write(1, "\n", 1);
	}
}

int	resolve(t_liste *list, int x, int y)
{
	t_grid grid;

	ft_bzero(&grid, sizeof(t_grid));
	if (!init_grid(&grid))
		return (0);
	while (!is_solution(&grid, list, x, y))
	{
		++grid.size;
		if (!check_capa(&grid))
			return (0);
	}
	show_grid(&grid);
	free_grid(&grid);
	return (1);
}

int main(void)
{
	t_liste list;
	int elem[20] = {2, 6, 7, 7, 4, 7, 10, 1, 14, 3, 7, 16};
	list.elem = (int *)elem;
	list.size = 12;
	resolve(&list, 0, 0);
	return (0);
}