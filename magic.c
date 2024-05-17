/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:10:19 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 17:46:20 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	magic(t_point *p)
{
	float	max_x;
	float	min_x;
	float	max_y;
	float	min_y;
	float	push_x;
	float	push_y;
	float	scal_x;
	float	scal_y;
	t_point	*pp;

	max_x = 0;
	min_x = 0;
	max_y = 0;
	min_y = 0;
	pp = &(*p);
	while (p)
	{
		p->x_p = cos(D45) * p->x + -sin(D45) * p->z;
		p->z = sin(D45) * p->x + cos(D45) * p->z;
		p->y_p = cos(D35) * p->y + sin(D35) * p->z;
		p->z = -sin(D35) * p->y + cos(D35) * p->z;
		p->x_p *= 50;
		p->y_p *= 50;
		if (p->x_p > max_x)
			max_x = p->x_p;
		if (p->x_p < min_x)
			min_x = p->x_p;
		if (p->y_p > max_y)
			max_y = p->y_p;
		if (p->y_p < min_y)
			min_y = p->y_p;
		p = p->next;
	}
	scal_x = (WIN_WIDTH - 100) / (fabs(max_x) + fabs(min_x));
	scal_y = (WIN_HEIGHT - 100) / (fabs(min_y) + fabs(max_y));
	push_x = (max_x + min_x) / 2;
	push_y = (max_y + min_y) / 2;
	p = pp;
	while (p)
	{
		p->x_p = (p->x_p * scal_x) + (WIN_WIDTH / 2 - scal_x * push_x);
		p->y_p = (p->y_p * scal_y) + (WIN_HEIGHT / 2 - scal_y * push_y);
		p = p->next;
	}
}
