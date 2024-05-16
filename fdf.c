/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:33 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/16 17:34:07 by jlinguet         ###   ########.fr       */
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

void	print_points(t_point *lst)
{
	int	i;

	// a enlever
	i = 0;
	while (lst)
	{
		printf("[point %i] x = %i, y = %i, z = %f\n",
			i++, lst->x, lst->y, lst->z);
		lst = lst->next;
	}
}

void	print_points2D(t_point *lst)
{
	int	i;

	// a enlever
	i = 0;
	while (lst)
	{
		printf("[point %i] x = %f, y = %f --- \n",
			i++, lst->x_p, lst->y_p);
		lst = lst->next;
	}
}

void	magic(t_point *p)
{
	float	push_x;
	float	push_y;
	t_point *pp;

	pp = &(*p);
	push_x = p->x / 2;
	push_y = p->y / 2;
	while (p)
	{
		p->x_p = cos(D45) * p->x + -sin(D45) * p->z;
		p->z = sin(D45) * p->x + cos(D45) * p->z;
		p->y_p = cos(D35) * p->y + sin(D35) * p->z;
		p->z = -sin(D35) * p->y + cos(D35) * p->z;
		p->x_p = p->x_p * 50;
		p->y_p = p->y_p * 50;
		if (p->x == push_x && p->y == push_y)
		{
			push_x = p->x_p;
			push_y = p->y_p;
		}
		p = p->next;
	}
	p = pp;
	while (p)
	{
		p->x_p += (WIN_WIDTH / 2 - push_x);
		p->y_p += (WIN_HEIGHT / 2 - push_y);
		p = p->next;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_point	*pts;

	pts = NULL;
	fd = check_file(ac, av);
	if (fd == -1 || parse_file(fd, av[1], &pts) == -1)
		return (clear_pts(&pts), 1);
	print_points(pts);
	printf("\n\n");
	magic(pts);
	print_points2D(pts);
	if (mlx_letsgo(pts, av[1]) == -1)
		return (clear_pts(&pts), 1);
	return (clear_pts(&pts), ft_printf("KO\n"), 0);
}
