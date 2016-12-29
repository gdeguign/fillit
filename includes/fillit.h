/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:08:02 by gdeguign          #+#    #+#             */
/*   Updated: 2016/12/29 11:09:45 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

#define CARRE        "##\n##\0"
#define BARRE_V     "#\n#\n#\n#\0"
#define BARRE_H     "####\0"
#define Z1            "##\n.##\0"
#define Z2            ".##\n##\0"
#define Z3            ".#\n##\n#\0"
#define Z4            "#\n##\n.#\0"
#define L_H1        "#\n###\0"
#define L_H2        "###\n#\0"
#define L_H3        "..#\n###\0"
#define L_H4        "###\n..#\0"
#define L_V1        "##\n#\n#\0"
#define L_V2        "#\n#\n##\0"
#define L_V3        ".#\n.#\n##\0"
#define L_V4        "##\n.#\n.#\0"
#define T1            ".#\n###\0"
#define T2            "#\n##\n#\0"
#define T3            "###\n.#\0"
#define T4            ".#\n##\n.#\0"

typedef struct	s_liste
{
	int			*elem;
	int			size;
	int			capacite;
}				t_liste;

#endif
