#ifndef FILLIT_RESOLVE_H
# define FILLIT_RESOLVE_H

typedef struct			s_grid
{
	char				**grid;
	int					size;
	int					capacity;
}						t_grid;

typedef struct			s_coord
{
	int					*x;
	int					*y;
}						t_coord;

int is_solution(t_grid *grid, t_liste *list, int x, int y);
void show_grid(t_grid *grid);

#endif