/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:05:30 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/08 12:05:53 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf fdf, t_point a, t_point b)
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
		mlx_pixel_put(fdf.mlx, fdf.win, round(a.x_p), round(a.y_p), PIXEL_COLOR);
		a.x_p += dx;
		a.y_p += dy;
		steps--;
	}
}
