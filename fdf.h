/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:01 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/02 19:47:13 by jlinguet         ###   ########.fr       */
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
	float	x;
	float	y;
	float	z;
	struct s_point	*next;
}	t_point;

# define CROSS_CLICKED 131072

# define PIXEL_COLOR 255

int		mlx_lestgo(void);

void	draw_line(t_fdf fdf, t_point a, t_point b);

t_point	*parse_file(int fd);

#endif
