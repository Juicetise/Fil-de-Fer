/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:35:28 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/02 14:35:30 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_xnb(char *line)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			n++;
		while (line[i] && line[i] != ' ')
			i++;
		while (line[i] && line[i] == ' ')
			i++;
	}
	return (n);
}

void	countxy(char *file, t_q *q)
{
	char	*line;
	int		x;
	int		y;
	int		l;
	int		fd;

	l = 0;
	y = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		l = define_xnb(line);
		if (l > x)
			x = l;
		y++;
		if (line)
			free(line);
	}
	close(fd);
	q->x_nb = x;
	q->y_nb = y;
}

int		main(int argc, char **argv)
{
	t_q	*q;

	q = (t_q *)malloc(sizeof(t_q));
	init(q, argv[1]);
	mlx_hook(q->wn, 2, (1L << 0), my_key_funct, q);
	mlx_mouse_hook(q->wn, my_mouse_funct, q);
	mlx_expose_hook(q->wn, expose_fdf, q);
	mlx_loop(q->mx);
}
