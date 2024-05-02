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

void	draw_line(t_fdf fdf, t_point a, t_point b)
{
	float	dx;
	float	dy;
	float	steps;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	dx /= steps;
	dy /= steps;
	while (steps > 0)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, round(a.x), round(a.y), PIXEL_COLOR);
		a.x += dx;
		a.y += dy;
		steps--;
	}
}
