/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:05:30 by jlinguet          #+#    #+#             */
/*   Updated: 2024/04/23 16:05:33 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lowright_corner(t_fdf fdf, t_point a, t_point b)
{
	int	dx;
	int	dy;
	int	e;

	e = b.x - a.x;
	dx = e * 2;
	dy = (b.y - a.y) * 2;
	while (a.x <= b.x)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, a.x, a.y, PIXEL_COLOR);
		a.x += 1;
		e -= dy;
		if (e <= 0)
		{
			a.y += 1;
			e += dx;
		}
	}
	mlx_pixel_put(fdf.mlx, fdf.win, b.x, b.y, PIXEL_COLOR);
}

void	draw_line(t_fdf fdf, t_point a, t_point b)
{
	float	dx;
	float	dy;
	float	steps;
	float	xinc;
	float	yinc;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xinc = dx / (float)steps;
	yinc = dy / (float)steps;
	while (steps > 0)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, round(a.x), round(a.y), PIXEL_COLOR);
		a.x += xinc;
		a.y += yinc;
		steps--;
	}
}
