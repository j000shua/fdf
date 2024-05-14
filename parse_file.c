/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:11:23 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/14 18:04:45 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_point(t_point **pts, float x, float y, float z)
{
	t_point	*new;

	new = malloc(sizeof(t_point));
	if (!new)
		return (-1);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = *pts;
	*pts = new;
	return (0);
}

void	clear_pts(t_point **pts)
{
	t_point	*next;

	while (*pts)
	{
		next = (*pts)->next;
		free(*pts);
		*pts = next;
	}
}

int	parse_file(int fd, t_point **pts)
{
	char	*line;
	char	**vals;
	int		lx;
	int		x;
	int		y;

	line = get_next_line(fd);
	y = -1;
	while (y++, line)
	{
		vals = ft_split(line, " \t\n\v\f\r");
		if (free(line), !vals || !*vals)
			return (clear_pts(pts), free_tab(vals), -1);
		x = -1;
		while (vals[++x])
			if (add_point(pts, x, y, ft_atoi(vals[x])) == -1)
				return (clear_pts(pts), free_tab(vals), -1);
		if (free_tab(vals), y > 0 && lx != x)
			return (clear_pts(pts), -1);
		lx = x;
		line = get_next_line(fd);
	}
	return (0);
}
