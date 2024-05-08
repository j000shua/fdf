/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_letsgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:22:07 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/08 14:37:31 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_prog(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
}

int	key(int keycode, t_fdf *fdf)
{
	if (keycode == ECHAP_KEY)
		quit_prog(fdf);
	return (0);
}

void	draw_grid(t_fdf fdf, t_point *pts)
{
	float 	max_x;
	float	i;
	t_point	*up;

	max_x = pts->x / 200 + 1;
	i = 0;
	up = pts;
	while (pts->next)
	{
		if (pts->x != 0)
			draw_line(fdf, *pts, *pts->next);
 		if (pts->y != 0)
		{
			while (i++ < max_x)
				up = up->next;
			draw_line(fdf, *pts, *up);
			i = 0;
		}
		pts = pts->next;
		up = pts;
	}
}

int	mlx_lestgo(t_point *pts)
{
	t_fdf	fdf;

	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
		return (-1);
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, "fdf");
	// taille a determiner (+ mettre en titre le nom du ficher)
	if (fdf.win == NULL)
		return (free(fdf.mlx), -1);
	draw_grid(fdf, pts);	
	mlx_key_hook(fdf.win, key, &fdf);
	mlx_hook(fdf.win, CROSS_BUTTON, CROSS_CLICKED, quit_prog, &fdf);
/* 	while (pts->next)
	{
		draw_line(fdf, *pts, *pts->next);
		pts = pts->next;
	} */
	
	mlx_loop(fdf.mlx);
	return (0);
}
