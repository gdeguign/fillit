#include "fillit_resolve.h"

int add_tetriminos_0(t_grid *grid, int i, int x, int y);
int add_tetriminos_1(t_grid *grid, int i, int x, int y);
int add_tetriminos_2(t_grid *grid, int i, int x, int y);
int add_tetriminos_3(t_grid *grid, int i, int x, int y);
int add_tetriminos_4(t_grid *grid, int i, int x, int y);
int add_tetriminos_5(t_grid *grid, int i, int x, int y);
int add_tetriminos_6(t_grid *grid, int i, int x, int y);
int add_tetriminos_7(t_grid *grid, int i, int x, int y);
int add_tetriminos_8(t_grid *grid, int i, int x, int y);
int add_tetriminos_9(t_grid *grid, int i, int x, int y);
int add_tetriminos_10(t_grid *grid, int i, int x, int y);
int add_tetriminos_11(t_grid *grid, int i, int x, int y);
int add_tetriminos_12(t_grid *grid, int i, int x, int y);
int add_tetriminos_13(t_grid *grid, int i, int x, int y);
int add_tetriminos_14(t_grid *grid, int i, int x, int y);
int add_tetriminos_15(t_grid *grid, int i, int x, int y);
int add_tetriminos_16(t_grid *grid, int i, int x, int y);
int add_tetriminos_17(t_grid *grid, int i, int x, int y);
int add_tetriminos_18(t_grid *grid, int i, int x, int y);

int (*g_add_tetriminos[])(t_grid *grid, int i, int x, int y)={
	&add_tetriminos_0,
	&add_tetriminos_1,
	&add_tetriminos_2,
	&add_tetriminos_3,
	&add_tetriminos_4,
	&add_tetriminos_5,
	&add_tetriminos_6,
	&add_tetriminos_7,
	&add_tetriminos_8,
	&add_tetriminos_9,
	&add_tetriminos_10,
	&add_tetriminos_11,
	&add_tetriminos_12,
	&add_tetriminos_13,
	&add_tetriminos_14,
	&add_tetriminos_15,
	&add_tetriminos_16,
	&add_tetriminos_17,
	&add_tetriminos_18
};


int remove_tetriminos_0(t_grid *grid, int x, int y);
int remove_tetriminos_1(t_grid *grid, int x, int y);
int remove_tetriminos_2(t_grid *grid, int x, int y);
int remove_tetriminos_3(t_grid *grid, int x, int y);
int remove_tetriminos_4(t_grid *grid, int x, int y);
int remove_tetriminos_5(t_grid *grid, int x, int y);
int remove_tetriminos_6(t_grid *grid, int x, int y);
int remove_tetriminos_7(t_grid *grid, int x, int y);
int remove_tetriminos_8(t_grid *grid, int x, int y);
int remove_tetriminos_9(t_grid *grid, int x, int y);
int remove_tetriminos_10(t_grid *grid, int x, int y);
int remove_tetriminos_11(t_grid *grid, int x, int y);
int remove_tetriminos_12(t_grid *grid, int x, int y);
int remove_tetriminos_13(t_grid *grid, int x, int y);
int remove_tetriminos_14(t_grid *grid, int x, int y);
int remove_tetriminos_15(t_grid *grid, int x, int y);
int remove_tetriminos_16(t_grid *grid, int x, int y);
int remove_tetriminos_17(t_grid *grid, int x, int y);
int remove_tetriminos_18(t_grid *grid, int x, int y);

int (*g_remove_tetriminos[])(t_grid *grid, int x, int y)=
{
	&remove_tetriminos_0,
	&remove_tetriminos_1,
	&remove_tetriminos_2,
	&remove_tetriminos_3,
	&remove_tetriminos_4,
	&remove_tetriminos_5,
	&remove_tetriminos_6,
	&remove_tetriminos_7,
	&remove_tetriminos_8,
	&remove_tetriminos_9,
	&remove_tetriminos_10,
	&remove_tetriminos_11,
	&remove_tetriminos_12,
	&remove_tetriminos_13,
	&remove_tetriminos_14,
	&remove_tetriminos_15,
	&remove_tetriminos_16,
	&remove_tetriminos_17,
	&remove_tetriminos_18
};