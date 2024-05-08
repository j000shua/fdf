/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:24:56 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/08 14:32:44 by jlinguet         ###   ########.fr       */
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

int	check_rect(t_point *pts)
{
	int	x;
	int	y;

	if (pts == NULL)
		return (0);
	x = pts->x;
	y = pts->y;
	while (pts)
	{
		if (pts->y == y - 1)
		{
			y--;
			if (x != pts->x)
				return (-1);
		}
		pts = pts -> next;
	}
	return (0);
}

int	parse_file(int fd, t_point **pts)
{
	char	*line;
	char	**vals;
	int		x;
	float	y;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		vals = ft_split(line, " \t\n\v\f\r");
		free(line);
		if (!vals || !*vals)
			return (free_tab(vals), -1);
		x = -1;
		while (vals[++x])
		{
			if (add_point(pts, x*200, y*200, (float)ft_atoi(vals[x])) == -1)
				return (free_tab(vals), exit(1), -1);
		}
		free_tab(vals);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (check_rect(*pts));
}
