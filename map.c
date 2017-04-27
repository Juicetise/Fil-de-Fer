/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 18:21:30 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/03 18:21:32 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(t_q *q, char **split, int *x, int y)
{
	int		j;

	j = 0;
	while (split[j] && *x != q->x_nb)
	{
		q->tab[y][*x] = ft_atoi(split[j]);
		(*x)++;
		j++;
	}
	while (*x != q->x_nb)
	{
		q->tab[y][*x] = 0;
		(*x)++;
	}
}

void	gene_map(char *file, t_q *q, int x, int y)
{
	char	*line;
	char	**split;
	int		fd;
	int		i;

	split = NULL;
	if (!file)
		return ;
	fd = open(file, O_RDONLY);
	q->tab = (int **)malloc(sizeof(int *) * q->y_nb);
	while (get_next_line(fd, &line) == 1 && y != q->y_nb)
	{
		q->tab[y] = (int *)malloc(sizeof(int) * q->x_nb);
		split = ft_strsplit(line, ' ');
		if (split)
			fill_map(q, split, &x, y);
		x = 0;
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
		free(line);
		y++;
	}
	close(fd);
}
