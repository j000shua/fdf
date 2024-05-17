/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:45:00 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 17:45:16 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int		offset;
	char	*dst;

	offset = (x * (img->bpp / 8)) + (y * img->size_line);
	dst = img->data + offset;
	*(int *)(dst) = color;
}
