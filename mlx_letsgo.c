/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_letsgo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:22:07 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/07 09:08:24 by jlinguet         ###   ########.fr       */
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

int	mlx_lestgo(void)
{
	int		scroll;
	t_fdf	fdf;

	scroll = 0;
	fdf.mlx = mlx_init();
	if (fdf.mlx == NULL)
		return (-1);
	fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, "fdf");
	// taille a determiner (+ mettre en titre le nom du ficher)
	if (fdf.win == NULL)
		return (free(fdf.mlx), -1);
	mlx_key_hook(fdf.win, key, &fdf);
	mlx_hook(fdf.win, CROSS_BUTTON, CROSS_CLICKED, quit_prog, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
