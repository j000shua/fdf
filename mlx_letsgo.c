/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_letsgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:22:07 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 17:47:39 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	quit_prog(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	clear_pts(&fdf->pts);
	exit(0);
}

int	key(int keycode, t_fdf *fdf)
{
	if (keycode == ECHAP_KEY)
		quit_prog(fdf);
	return (0);
}

void	draw_line(t_img *img, t_point a, t_point b)
{
	float	dx;
	float	dy;
	float	steps;

	dx = b.x_p - a.x_p;
	dy = b.y_p - a.y_p;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	dx /= steps;
	dy /= steps;
	while (steps > 0)
	{
		my_pixel_put(img, round(a.x_p), round(a.y_p), COLOR);
		a.x_p += dx;
		a.y_p += dy;
		steps--;
	}
}

void	draw_grid(t_point *pts, t_img *img)
{
	float	max_x;
	float	i;
	t_point	*up;

	max_x = pts->x + 1;
	i = 0;
	up = pts;
	while (pts->next)
	{
		if (pts->x != 0)
			draw_line(img, *pts, *pts->next);
		if (pts->y != 0)
		{
			while (i++ < max_x)
				up = up->next;
			draw_line(img, *pts, *up);
			i = 0;
		}
		pts = pts->next;
		up = pts;
	}
}

int	mlx_letsgo(t_point *pts, char *name)
{
	t_fdf	fdf;
	t_img	i;
	int		endian;

	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
		return (clear_pts(&pts), -1);
	fdf.img = mlx_new_image(fdf.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (fdf.img == NULL)
		return (free(fdf.mlx), clear_pts(&pts), -1);
	i.data = mlx_get_data_addr(fdf.img, &i.bpp, &i.size_line, &endian);
	draw_grid(pts, &i);
	fdf.pts = pts;
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, name);
	if (fdf.win == NULL)
		return (free(fdf.mlx), clear_pts(&pts), -1);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img, 0, 0);
	mlx_key_hook(fdf.win, key, &fdf);
	mlx_hook(fdf.win, CROSS_BUTTON, CROSS_CLICKED, quit_prog, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
