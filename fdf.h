/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdurand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:35:37 by pdurand           #+#    #+#             */
/*   Updated: 2017/04/02 14:35:39 by pdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define RED 0x00E74C3C
# define BLUE 0x005DADE2
# define GREEN 0x002ECC71
# define YELLOW 0x00F1C40F
# define GREY 0x00BDC3C7
# define BROWN 0x00D35400
# define PURPLE 0x009B59B6
# define WHITE 0x00F7F9F9
# define ORANGE 0x00F39C12
# define BLACK 0x00000000
# define COEFFICIENT 0.5
# define COEFFICIENT2 0.6
# define O 31

typedef struct		s_q
{
	int				**tab;
	int				height;
	int				weight;
	char			*item;
	void			*mx;
	void			*wn;
	int				x;
	void			*img;
	int				y;
	int				x_nb;
	int				y_nb;
	int				x_max;
	int				y_max;
	int				x_base;
	int				y_base;
	int				color;
	int				x_ratio;
	int				y_ratio;
	int				xi;
	int				yi;
	int				zoom;
	int				vert;
	int				hor;
	int				z;
	int				form;
	int				colortmp;
	char			*argv;
	int				tmp;
	double			a;
	double			zoo;
	int				U;
	int				V;
	int				bpp;
	int				len;
	int				endian;
	char			*data;
}					t_q;

int					clear_image(t_q *q, int x, int y);
int					expose_fdf(t_q *q);
void				pxl2img(t_q *q, int x, int y, int color);
void				numpad(int keycode, t_q *q);
void				drawclear(t_q *q);
void				draw_h(t_q *q);
int					my_key_funct(int keycode, t_q *q);
void				hypno(t_q q);
void				draw_right(t_q *q, int x1, int x2, int y1, int y2);
void				draw_left(t_q *q, int x1, int x2, int y1, int y2);
void				draw_up(t_q *q, int x1, int x2, int y1, int y2);
void				ligne(t_q q, int x1, int x2, int y1, int y2);
void				draw_down(t_q *q, int x1, int x2, int y1, int y2);
void				gene_map(char *file, t_q *q, int x, int y);
void				fill_map(t_q *q, char **split, int *x, int y);
void				ft_line(int x1, int x2, int y1, int y2, t_q q);
int					abs(int j);
void				ft_redcube(t_q q);
void				ft_circle(t_q *q, int x0, int y0, int radius);
void				draw(t_q *q);
void				draw_v(t_q *q);
void				init(t_q *q, char *argv);
void				countxy(char *file, t_q *q);
int					my_mouse_funct(int keycode, int x, int y, t_q *q);
void				ft_circle(t_q *q, int x0, int y0, int radius);
int					ft_close(t_q *q);

#endif
