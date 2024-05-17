/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:10:19 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 18:55:45 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	more_magic(t_point *p, t_transform t);

void	magic(t_point *p)
{
	t_transform		t;
	t_point			*pp;

	t.max_x = 0;
	t.min_x = 0;
	t.max_y = 0;
	t.min_y = 0;
	pp = &(*p);
	while (p)
	{
		p->x_p = cos(DY) * p->x + -sin(DY) * p->z;
		p->z = sin(DY) * p->x + cos(DY) * p->z;
		p->y_p = cos(DX) * p->y + sin(DX) * p->z;
		if (p->x_p > t.max_x)
			t.max_x = p->x_p;
		if (p->x_p < t.min_x)
			t.min_x = p->x_p;
		if (p->y_p > t.max_y)
			t.max_y = p->y_p;
		if (p->y_p < t.min_y)
			t.min_y = p->y_p;
		p = p->next;
	}
	p = pp;
	more_magic(p, t);
}

void	more_magic(t_point *p, t_transform t)
{
	float	w_margin;
	float	h_margin;

	w_margin = WIN_WIDTH * ((float)W_MARGIN / 100);
	h_margin = WIN_HEIGHT * ((float)H_MARGIN / 100);
	t.scal_x = (WIN_WIDTH - w_margin) / (fabs(t.max_x) + fabs(t.min_x));
	t.scal_y = (WIN_HEIGHT - h_margin) / (fabs(t.min_y) + fabs(t.max_y));
	t.push_x = (t.max_x + t.min_x) / 2;
	t.push_y = (t.max_y + t.min_y) / 2;
	while (p)
	{
		p->x_p = (p->x_p * t.scal_x) + (WIN_WIDTH / 2 - t.scal_x * t.push_x);
		p->y_p = (p->y_p * t.scal_y) + (WIN_HEIGHT / 2 - t.scal_y * t.push_y);
		p = p->next;
	}
}
