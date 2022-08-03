/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 13:19:36 by schuah            #+#    #+#             */
/*   Updated: 2022/08/03 18:58:54 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_BONUS_H
# define SL_BONUS_H

# include "../libft/srcs/libft.h"
# include "../libft/srcs/get_next_line.h"
# include "../libft/srcs/ft_printf.h"
# include <mlx.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Player prefs */
# define PLY_MVSPD	64
# define FPS		10

/* The 4 values that define a color
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

all info needed for an image
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image; */

/* Vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/* Image info */
typedef struct s_image {
	void		*ref;
	t_vector	size;
}	t_image;

/* Player info */
typedef struct s_player
{
	int			alive;
	int			pickups;
	int			moves;
	t_vector	pos;
	t_image		image;
}	t_player;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*ref;
	int			frame;
	t_vector	size;
}	t_window;

/* A struct storing all map data */
typedef struct s_map {
	int			x;
	int			y;
	int			n_pick;
	t_vector	start;
	t_vector	exit;
	char		**layout;
	t_image		pickup_img;
	t_image		wall_img;
	t_image		exit_img;
	t_image		spc_img;
}	t_map;

/* The gamemaster or game manager that holds all the game's value */
typedef struct s_gm {
	void		*mlx;
	t_window	window;
	t_player	player;
	t_map		map;
}	t_gm;

/* Window functions */
void	sl_newwindow(t_gm *gm, int height, int width, char *name);
int		sl_update(t_gm *gm);
int		sl_exit(t_gm *gm);
void	sl_putimage(t_gm *gm);
void	sl_displaymap(t_gm *gm);
void	sl_hooks(t_gm *gm);

/* Player functions */
void	sl_defaultplayer(t_gm *gm);
int		sl_getinput(int keycode, t_gm *gm);
void	sl_playeranim(t_gm *gm);
void	sl_movement(t_gm *gm, int keycode);
void	sl_mapevents(t_gm *gm);

/* Map functions */
int		sl_getmap(t_gm *gm, int ac, char **av);
void	sl_defaultmap(t_gm *gm);

/* Helper functions */
void	sl_printply(t_gm *gm);
void	sl_printmap(t_gm *gm);
void	sl_freeeverything(t_gm *gm);

#endif