/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:33 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 18:47:21 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(int ac, char **av)
{
	int	len;
	int	fd;

	if (ac != 2)
		return (ft_fprintf(2, ERR_ARGS), -1);
	len = ft_strlen(av[1]);
	if (len <= 4 || ft_strncmp(&av[1][len - 4], ".fdf", 4))
		return (ft_fprintf(2, ERR_FILE), -1);
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
		return (close(fd), ft_fprintf(2, ERR_DIR, av[1]), -1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror(av[1]), -1);
	return (fd);
}

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

int	parse_file(int fd, char *name, t_point **pts)
{
	char	*line;
	char	**vals;
	int		lx;
	int		x;
	int		y;

	line = get_next_line(fd);
	if (line == NULL)
		return (ft_fprintf(2, ERR_LINE, name), -1);
	y = -1;
	while (y++, line)
	{
		vals = ft_split(line, " \t\n\v\f\r");
		if (free(line), !vals || !*vals)
			return (free_tab(vals), ft_fprintf(2, ERR_LINE, name), -1);
		x = -1;
		while (vals[++x])
			if (add_point(pts, x, y, ft_atoi(vals[x])) == -1)
				return (free_tab(vals), perror("add_point()"), -1);
		if (free_tab(vals), y > 0 && lx != x)
			return (ft_fprintf(2, ERR_RECT, name), -1);
		lx = x;
		line = get_next_line(fd);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_point	*pts;

	if (WIN_HEIGHT <= 0 || WIN_WIDTH <= 0 || H_MARGIN < 0 || W_MARGIN < 0)
		return (ft_fprintf(2, ERR_SIZE), 1);
	pts = NULL;
	fd = check_file(ac, av);
	if (fd == -1 || parse_file(fd, av[1], &pts) == -1)
		return (clear_pts(&pts), 1);
	magic(pts);
	if (mlx_letsgo(pts, av[1]) == -1)
		return (clear_pts(&pts), ft_fprintf(2, ERR_MLX), 1);
}
