#include "fdf.h"

void	pxl2img(t_q *q, int x, int y, int color)
{
	if (x > q->height || x < 0 || y > q->weight || y < 0)
		return	;
	*(int *)&q->data[(y * q->len) + (x * (q->bpp / 8))] = color;
}

int		expose_fdf(t_q *q)
{
	clear_image(q, 0, 0);
	draw(q);
	mlx_put_image_to_window(q->mx, q->wn, q->img, 0, 0);
	return (0);
}

int		clear_image(t_q *q, int x, int y)
{
	while (y < q->weight)
	{
		x = 0;
		while (x < q->height)
			pxl2img(q, x++, y, BLACK);
		y++;
	}
	return (0);
}
