/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 10:55:20 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 10:55:36 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_liste	*une_liste;

	une_liste = NULL;
	if (argc != 2)
	{
		ft_print("usage: fillit source_file\n");
		return (0);
	}
	if ((une_liste = parser(argv[1], une_liste)) == NULL)
		return (0);
	if (une_liste->error || une_liste->size == 0)
	{
		free_t_liste(une_liste);
		ft_print("error\n");
		return (0);
	}
	resolve(une_liste);
	free_t_liste(une_liste);
	return (0);
}
