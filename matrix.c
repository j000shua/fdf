/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:18:32 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/08 12:08:35 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_y(t_point **p, float y)
{
	t_point	r;
	float	cos_y;
	float	sin_y;

	r = **p;
	cos_y = cos(y);
	sin_y = sin(y);

	(*p)->x_p = (cos_y * r.x) + (-sin_y * r.z);
	(*p)->z = (sin_y * r.x) + (cos_y * r.z);
}

void	rotate_x(t_point **p, float x)
{
	t_point	r;
	float	cos_x;
	float	sin_x;

	r = **p;
	cos_x = cos(x);
	sin_x = sin(x);

	(*p)->y_p = (cos_x * r.y) + (sin_x * r.z);
	(*p)->z = (-sin_x * r.y) + (cos_x * r.z);
}

void	ft_3Dify(t_point *pts)
{
	while (pts)
	{
		rotate_y(&pts, 0.785398);
		rotate_x(&pts, 0.610865238);
		//project_xy(&pts);
		pts = pts->next;
	}
}