/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:29:44 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/03 18:29:45 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_q *q, char *argv)
{
	q->height = 1600;
	q->weight = 2600;
	q->zoom = 1;
	q->vert = 1180;
	q->hor = 2920;
	q->z = -4;
	q->form = 1;
	q->color = WHITE;
	q->tmp = 1;
	q->a = 0.1;
	q->zoo = 2;
	countxy(argv, q);
	gene_map(argv, q, 0, 0);
	q->mx = mlx_init();
	q->wn = mlx_new_window(q->mx, q->height, q->weight, "pdurand - FDF");
	q->img = mlx_new_image(q->mx, q->height, q->weight);
	q->data = mlx_get_data_addr(q->img, &q->bpp, &q->len, &q->endian);
}
