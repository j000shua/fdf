/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:01 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/15 17:51:37 by jlinguet         ###   ########.fr       */
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
# define CROSS_BUTTON  17
# define ECHAP_KEY     65307

# define D45 0.785398
# define D35 0.610865238

# define WIN_HEIGHT  1000
# define WIN_WIDTH   1000
# define PIXEL_COLOR 255

# define ERR_ARGS "Usage: ./fdf [MAP_NAME].fdf\n"
# define ERR_FILE "Usage: Map file must end with '.fdf'\n"
# define ERR_DIR  "%s: Is a directory\n"
# define ERR_LINE "%s: Map must not have empty lines\n"
# define ERR_RECT "%s: Map must be rectangle\n"

int		parse_file(int fd, char *name, t_point **pts);
void	clear_pts(t_point **pts);

#endif
