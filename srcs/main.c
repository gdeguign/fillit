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

#include "../includes/fillit.h"

int		parser(char *file_name)
{
	ft_print("okok");
}

int 	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	parser(argv[1]);
	return (0);
}
