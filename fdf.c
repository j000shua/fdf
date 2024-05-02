/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:33 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/02 19:45:40 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	printfd(int fd, char *s)
{
	return (write(fd, s, ft_strlen(s)));
}

int	check_file(int ac, char **av)
{
	int	len;
	int	fd;

	if (ac != 2)
		return (printfd(2, "Incorect arguments\n"), -1);
	len = ft_strlen(av[1]);
	if (len <= 4 || ft_strncmp(&av[1][len - 4], ".fdf", 4))
		return (printfd(2, "File must be *.fdf\n"), -1);
	fd = open(av[1], O_DIRECTORY);
	close(fd);
	if (fd > 0)
	{
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror(av[1]), -1);
	return (fd);
}

int	main(int ac, char **av)
{
	int		fd;
	t_point	*points;

	fd = check_file(ac, av);
	if (fd == -1)
		return (1);
	points = parse_file(fd);
	if (points == NULL)
		return (1);
	if (mlx_lestgo() == -1)
		return (printfd(2, "prout\n"), 1);
	return (0);
}
