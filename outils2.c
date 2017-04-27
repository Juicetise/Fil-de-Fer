/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:25:10 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/02 13:25:12 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_mouse_funct(int keycode, int x,  int y, t_q *q)
{
	int radius;
	
	radius = 10;
	if (keycode == 4)
		radius--;
	if (keycode == 5)
		radius++;
	if (keycode == 1)
		ft_circle(q, x, y, 10);
	return (0);
}
int		my_key_funct(int keycode, t_q *q)
{
	if (keycode == 33)
		q->z++;
	if (keycode == 30)
		q->z--;
	if (keycode == 258)
		q->form = -q->form;
	if (keycode == 125)
		q->hor = q->hor + 10;
	if (keycode == 126)
		q->hor = q->hor - 10;
	if (keycode == 123)
		q->vert = q->vert + 10;
	if (keycode == 124)
		q->vert = q->vert - 10;
	if (keycode > 81 && keycode < 93)
		numpad(keycode, q);
	if (keycode == 69 && q->zoo != 0.2)
		q->zoo = q->zoo - 0.19;
	if (keycode == 78)
		q->zoo = q->zoo + 0.19;
	if (q->color == BLACK)
		q->color = q->colortmp;
	if (keycode == 24)
		q->V = q->V + 100;
	if (keycode == 27 && q->V != -(q->height - 100))
		q->V = q->V - 100;
	if (keycode == 25 && q->U != -(q->weight - 100))
		q->U = q->U - 100;
	if (keycode == 29)
		q->U = q->U + 100;
	if (keycode == 53)
		ft_close(q);
	expose_fdf(q);
	return (0);
}

void	numpad(int keycode, t_q *q)
{
	if (keycode == 82)
		q->color = RED;
	if (keycode == 83)
		q->color = BLUE;
	if (keycode == 84)
		q->color = GREEN;
	if (keycode == 85)
		q->color = YELLOW;
	if (keycode == 86)
		q->color = GREY;
	if (keycode == 87)
		q->color = BROWN;
	if (keycode == 88)
		q->color = PURPLE;
	if (keycode == 89)
		q->color = ORANGE;
	if (keycode == 91)
		q->color = WHITE;
	if (q->color == BLACK)
		q->color = q->colortmp;
	if (keycode == 92)
		q->color = BLACK;
}

int		ft_close(t_q *q)
{
	mlx_clear_window(q->mx, q->wn);
	mlx_destroy_window(q->mx, q->wn);
	free(q);
	exit(0);
}
