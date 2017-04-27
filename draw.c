/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:35:59 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/02 14:36:00 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_right(t_q *q, int x1, int x2, int y1, int y2)
{
	int		x;

	x = x1 - 1;
	while (++x <= x2)
	{
		pxl2img(q, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), q->color);
	}
}

void	draw_left(t_q *q, int x1, int x2, int y1, int y2)
{
	int		x;

	x = x2 - 1;
	while (++x <= x1)
	{
		pxl2img(q, x, y2 + ((y1 - y2) * (x - x2)) / (x1 - x2), q->color);
	}
}

void	draw_up(t_q *q, int x1, int x2, int y1, int y2)
{
	int		y;

	y = y2 - 1;
	while (++y <= y1)
	{
		pxl2img(q, x2 + ((x1 - x2) * (y - y2)) / (y1 - y2), y, q->color);
	}
}

void	draw_down(t_q *q, int x1, int x2, int y1, int y2)
{
	int		y;

	y = y1 - 1;
	while (++y <= y2)
	{
		pxl2img(q, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y, q->color);
	}
}

void	ligne(t_q q, int x1, int x2, int y1, int y2)
{
	if (x1 <= x2 && (x2 - x1) >= abs(y2 - y1))
		draw_right(&q, x1, x2, y1, y2);
	else if (x2 <= x1 && (x1 - x2) >= abs(y1 - y2))
		draw_left(&q, x1, x2, y1, y2);
	else if (y2 <= y1 && (y1 - y2) >= abs(x1 - x2))
		draw_up(&q, x1, x2, y1, y2);
	else if (y1 <= y2 && (y2 - y1) >= abs(x2 - x1))
		draw_down(&q, x1, x2, y1, y2);
}
