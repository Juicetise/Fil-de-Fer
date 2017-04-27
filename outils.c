/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:35:46 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/02 14:35:47 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	triangulation(t_q *q)
{
	int z;
	int y;
	int x;
	int tmp1;
	int tmp2;

	y = q->yi;
	x = q->xi;
	q->xi = q->xi * (q->x_ratio + q->zoom) + q->hor;
	q->yi = q->yi * (q->y_ratio + q->zoom) + q->vert;
	z = q->tab[y][x] * q->form * q->z;
	q->xi = COEFFICIENT * q->xi - COEFFICIENT2 * q->yi;
	q->yi = z + (COEFFICIENT / 2) * q->xi + (COEFFICIENT2 / 2) * q->yi;
	if (q->tmp == -1)
	{
		tmp1 = q->xi;
		q->xi = (q->xi * cos(q->a)) - (q->yi * sin(q->a));
		q->yi = (tmp1 * sin(q->a)) + (q->yi * cos(q->a));
	}
}

void	draw_h(t_q *q)
{
	int	xtmp;
	int	ytmp;
	int	xtmp1;
	int	ytmp1;

	ytmp1 = 0;
	while (ytmp1 != q->y_nb)
	{
		xtmp = 0;
		ytmp = 0;
		xtmp1 = 0;
		while (xtmp1 != q->x_nb)
		{
			q->xi = xtmp1;
			q->yi = ytmp1;
			triangulation(q);
			if (xtmp != 0 || ytmp != 0)
				ligne(*q, xtmp, q->xi, ytmp, q->yi);
			xtmp = q->xi;
			ytmp = q->yi;
			xtmp1++;
		}
		ytmp1++;
	}
}

void	draw_v(t_q *q)
{
	int	xtmp;
	int	ytmp;
	int	xtmp1;
	int	ytmp1;

	xtmp1 = 0;
	while (xtmp1 != q->x_nb)
	{
		xtmp = 0;
		ytmp = 0;
		ytmp1 = 0;
		while (ytmp1 != q->y_nb)
		{
			q->xi = xtmp1;
			q->yi = ytmp1;
			triangulation(q);
			if (xtmp != 0 || ytmp != 0)
				ligne(*q, xtmp, q->xi, ytmp, q->yi);
			xtmp = q->xi;
			ytmp = q->yi;
			ytmp1++;
		}
		xtmp1++;
	}
}

void	draw(t_q *q)
{
	if (q->y_nb > 0 && q->x_nb > 0)
	{
		q->x_ratio = (q->weight + q->U) / (q->x_nb * q->zoo);
		q->y_ratio = (q->height + q->V) / (q->y_nb * q->zoo);
	}
	draw_h(q);
	draw_v(q);
}

void	ft_circle(t_q *q, int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int xChange = 1 - (radius << 1);
	int yChange = 0;
	int radiusError = 0;
	int i;
	
	while (x >= y)
	{
		i = x0 - x;
		while (i <= x0 + x)
		{
			mlx_pixel_put(q->mx, q->wn, i, y0 + y, 0x00FFFFFF);
			mlx_pixel_put(q->mx, q->wn, i, y0 - y, 0x00FFFFFF);
			i++;
		}
		i = x0 - y;
		while (i <= x0 + y)
		{
			mlx_pixel_put(q->mx, q->wn, i, y0 + x, 0x00FFFFFF);
			mlx_pixel_put(q->mx, q->wn, i, y0 - x, 0x00FFFFFF);
			i++;
		}
		
		y++;
		radiusError += yChange;
		yChange += 2;
		if (((radiusError << 1) + xChange) > 0)
		{
			x--;
			radiusError += xChange;
			xChange += 2;
		}
	}
}

