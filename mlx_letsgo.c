/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_letsgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:22:07 by jlinguet          #+#    #+#             */
/*   Updated: 2024/03/29 16:22:10 by jlinguet         ###   ########.fr       */
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
	if (keycode == 65307)
		quit_prog(fdf);
	return (0);
}

int	mouse(int button, int x, int y, int *param)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		*param += 1;
		printf("%i\n", *param);
	}
	if (button == 5)
	{
		*param -= 1;
		printf("%i\n", *param);
	}
	return (0);
}

int	mlx_lestgo(void)
{
	int		scroll;
	t_fdf	fdf;
	t_point	a;
	t_point	b;

	scroll = 0;
	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
		return (-1);
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, "test");
	if (fdf.win == NULL)
		return (free(fdf.mlx), -1);
	mlx_key_hook(fdf.win, key, &fdf);
	mlx_hook(fdf.win, 17, 1L << 17, quit_prog, &fdf);
	//mlx_mouse_hook(fdf.win, mouse, &scroll);
	a.x = 900;
	a.y = 100;
	b.x = 100;
	b.y = 900;
	draw_line(fdf, a, b);
	//printf("a.x = %i, a.y = %i, b.x = %i, b.y = %i\n", a.x, a.y, b.x, b.y);
 	a.x = 100;
	a.y = 550;
	b.x = 500;
	b.y = 123;
	draw_line(fdf, a, b);
	mlx_loop(fdf.mlx);
	return (0);
}
