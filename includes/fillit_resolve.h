/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:38:25 by ulefebvr          #+#    #+#             */
/*   Updated: 2017/01/03 14:38:34 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int						is_solution(t_grid *grid, t_liste *list);
void					show_grid(t_grid *grid);
int						space2keepgoing(t_grid *grid, t_liste *list);

#endif
