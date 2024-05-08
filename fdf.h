/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:01 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/08 12:03:51 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

/* open() */
# include <fcntl.h>

/* close(), read(), write() */
# include <unistd.h>

/* malloc(), free(), exit() */
# include <stdlib.h>

/* perror() */
# include <stdio.h>

/* strerror() */
# include <string.h>
# include <errno.h>

# include "../minilibx/mlx.h"
# include <math.h>

typedef struct s_fdf {
	void	*mlx;
	void	*win;
}	t_fdf;

typedef struct s_point {
	float			x;
	float			y;
	float			z;
	float			x_p;
	float			y_p;
	struct s_point	*next;
}	t_point;

# define CROSS_CLICKED 131072
# define CROSS_BUTTON 17
# define ECHAP_KEY 65307

# define PIXEL_COLOR 255

int		mlx_lestgo(t_point *pts);

void	draw_line(t_fdf fdf, t_point a, t_point b);

int		parse_file(int fd, t_point **pts);

void	ft_3Dify(t_point *pts);

#endif
