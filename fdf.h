/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:01 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/14 18:07:48 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"

# include "../mlx/mlx.h"
# include <math.h>

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

typedef struct s_point {
	int				x;
	int				y;
	int				z;
	float			x_p;
	float			y_p;
	struct s_point	*next;
}	t_point;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	t_point	*pts;
}	t_fdf;

# define CROSS_CLICKED 131072
# define CROSS_BUTTON 17
# define ECHAP_KEY 65307

# define PIXEL_COLOR 255

int		parse_file(int fd, t_point **pts);
void	clear_pts(t_point **pts);

#endif
