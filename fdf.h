/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:01 by jlinguet          #+#    #+#             */
/*   Updated: 2024/05/17 18:55:44 by jlinguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

# include "mlx.h"
# include "mlx_int.h"
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
	float			z;
	float			x_p;
	float			y_p;
	struct s_point	*next;
}	t_point;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	void	*img;
	t_point	*pts;
}	t_fdf;

typedef struct s_transform
{
	float	max_x;
	float	min_x;
	float	max_y;
	float	min_y;
	float	push_x;
	float	push_y;
	float	scal_x;
	float	scal_y;
}	t_transform;

# define DY 0.785398
# define DX 0.610865238

# define CROSS_CLICKED 131072
# define CROSS_BUTTON  17
# define ECHAP_KEY     65307

# define WIN_HEIGHT  1000
# define WIN_WIDTH   1000
# define H_MARGIN    10
# define W_MARGIN    10
# define COLOR       255

# define ERR_SIZE "Window size is impossible (defined in fdf.h)\n"
# define ERR_ARGS "Usage: ./fdf [MAP_NAME].fdf\n"
# define ERR_FILE "Usage: Map file must end with '.fdf'\n"
# define ERR_DIR  "%s: Is a directory\n"
# define ERR_LINE "%s: Map must not have empty lines\n"
# define ERR_RECT "%s: Map must be rectangle\n"
# define ERR_MLX  "An error has occured within the mlx functions\n"

void	clear_pts(t_point **pts);

void	magic(t_point *p);

int		mlx_letsgo(t_point *pts, char *name);

void	my_pixel_put(t_img *img, int x, int y, int color);

#endif

/*

void	print_points(t_point *lst)
{
	int	i;

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

	i = 0;
	while (lst)
	{
		printf("[point %i] x = %f, y = %f\n",
			i++, lst->x_p, lst->y_p);
		lst = lst->next;
	}
}

*/
